#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, x, y;

bool Chk(ll t) {
    if (t / x + t / y >= n - 1) return 1;
    return 0;
}

void solve() {
    
    cin >> n >> x >> y;

    if (x > y) swap(x, y);

    ll t;
    ll l = 1, r = LONG_LONG_MAX;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (Chk(mid)) {
            t = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << t + x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
