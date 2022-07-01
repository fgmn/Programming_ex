#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const int Mod = 1e9 + 7;
int C[15][15];

struct mat
{
	int n;
	vector<vector<long long>> x;

	// 构造函数
	explicit mat(int sz) : x(sz, vector<long long>(sz)) { n = sz; }

	// 单位矩阵
	void emat()
	{
		for (int i = 0; i < n; i++) {
			x[i][i] = 1;
		}
	}

	// 重载乘号
	mat operator*(const mat &a) const
	{
		mat res(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					res.x[i][j] = (res.x[i][j] + x[i][k] * a.x[k][j]) % Mod;
				}
			}
		}
		return res;
	}
};

// 矩阵快速幂
mat matqp(mat a, long long b)
{
	mat res(a.n);
	res.emat();
	while (b)
	{
		if (b & 1) res = res * a;	// 重载*乘法
		a = a * a;
		b >>= 1;
	}
	return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    mat t(k + 2);

    // 组合数计算 C00 = 0
    for (int i = 0; i <= k; i++) C[i][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            // cout << "C[" << i << "][" << j << "] = " << C[i][j] << ' ';
        }
        // cout << '\n';
    }

    // 构造转移矩阵
    t.x[0][0] = 1;
    for (int i = 1; i < k + 2; i++) {
        t.x[0][i] = C[k][i - 1];
    }

    for (int i = 1; i <= k; i++) {
        for (int j = i; j < k + 2; j++) {
            t.x[i][j] = C[k - i + 1][j - i];
        }
    }
    t.x[k + 1][k + 1] = 1;

    mat res = matqp(t, n - 1);
    // 初始状态s1=[1,1,...,1]^T
    ll ans = 0;
    for (int i = 0; i < k + 2; i++) {
        ans = (ans + res.x[0][i]) % Mod;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
