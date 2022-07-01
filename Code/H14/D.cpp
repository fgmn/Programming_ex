#include<iostream>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

ll f[5005][2];
ll sum[5005];   // 前缀和优化

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    f[a][0] = 1;
    for (int j = 1; j <= n; j++) {
        sum[j] = sum[j - 1] + f[j][0];
        sum[j] %= mod;
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            int l, r;
            if (j > b) {
                l = (j + b) / 2 + 1;
                r = n;
            }
            else if (j < b) {
                l = 1;
                r = (j + b - 1) / 2;
            }
            else continue;
            f[j][i & 1] = sum[r] - sum[l - 1] - f[j][1 - (i & 1)];
            f[j][i & 1] = (f[j][i & 1] + mod) % mod;
            // cout << f[j][i & 1] << ' ';
        }
        // cout << '\n';
        for (int j = 1; j <= n; j++) {
            sum[j] = sum[j - 1] + f[j][i & 1];
            sum[j] %= mod;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[i][k & 1];
        ans %= mod;
    }
    cout << ans;
    return 0;
}
