#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> f(n + 1);
    vector<bool> vis(n, 0);

    int v;
    for (int i = 1; i <= m; i++) {
        cin >> v;
        vis[v] = 1;
    }

    ll psum = 1;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i > k) {
            psum -= f[i - k - 1];
            psum = (psum + mod) % mod;
        }
        if (vis[i]) continue;
        f[i] = psum;
        psum = (f[i] + psum) % mod;
    }

    cout << f[n] << '\n';
    return 0;
}
