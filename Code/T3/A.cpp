#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll cal(ll x) {
    return x * (x + 1) / 2;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }

    ll ans = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, cal(b[i]) + cal(b[n] - b[i]));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
