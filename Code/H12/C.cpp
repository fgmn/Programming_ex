#include<iostream>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
int w[N], c[N], k[N];
int W[N], C[N];
ll f[N];

void solve() {
    int n, v;
    cin >> n >> v;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i] >> k[i];
    }

    // 二进制拆分
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int t = k[i];
        for (int j = 1; j <= t; j <<= 1) {
            cnt++;
            C[cnt] = j * c[i];
            W[cnt] = j * w[i];
            t -= j;
        }
        if (t > 0) {
            cnt++;
            C[cnt] = t * c[i];
            W[cnt] = t * w[i];
        }
    }

    for (int i = 1; i <= cnt; i++) {
        for (int j = v; j > 0; j--) {
            if (j >= W[i])
                f[j] = max(f[j], f[j - W[i]] + C[i]);
            else break;
        }
    }

    cout << f[v] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
