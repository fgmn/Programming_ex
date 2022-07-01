#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[100010];

void solve() {
    ll n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int ans = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] + k >= a[i + 1])
            ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
