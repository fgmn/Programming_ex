#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;

struct mat
{
	int n;
	vector<vector<long long>> x;

	// 构造函数
	explicit mat(int sz) : x(sz, vector<long long>(sz)) { n = sz; }

	// 单位矩阵
	void emat() {}  // 重载运算之后单位矩阵的定义可能变化

	// 重载乘号
	mat operator*(const mat &a) const
	{
		mat res(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					res.x[i][j] = max(res.x[i][j], x[i][k] + a.x[k][j]);
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
        // cout << "b = " << b << '\n';
		if (b & 1) res = res * a;	// 重载*乘法
        /*for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < a.n; j++) {
                cout << res.x[i][j] << ' ';
            }
            cout << '\n';
        }*/
        a = a * a;
		b >>= 1;
	}
	return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    mat t(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t.x[j][i];
        }
    }

    mat res = matqp(t, n - 1);
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, res.x[i][j]);
            // cout << res.x[i][j] << ' ';
        }
        // cout << '\n';
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
