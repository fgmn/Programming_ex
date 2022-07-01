#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const int Mod = 998244353;

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
    int n; cin >> n;

    mat t(4);

    t.x[0][0] = 1; t.x[0][1] = 1; t.x[0][2] = 1; t.x[0][3] = 0;
    t.x[1][0] = 1; t.x[1][1] = 1; t.x[1][2] = 0; t.x[1][3] = 1;
    t.x[2][0] = 1; t.x[2][1] = 0; t.x[2][2] = 1; t.x[2][3] = 1;
    t.x[3][0] = 0; t.x[3][1] = 1; t.x[3][2] = 1; t.x[3][3] = 1;
    mat res = matqp(t, n);
    // 初始状态为[1,0,0,0]^T
    cout << res.x[0][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}
