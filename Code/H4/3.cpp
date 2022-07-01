#include<bits/stdc++.h>
using namespace std;
using ll = long long;

/*
1
5
0 1 1 2 3
1 0 1 1
*/

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0, t = 0, b;   // ans : 最大收益 t : 最少交易次数 b : 差分
    bool flag = 1;
    for (int i = 1; i < n; i++) {
        b = a[i] - a[i - 1];
        if (b > 0) {
            ans += b;
            if (flag) {
                t++;
                flag = 0;
            }
        }
        else if ((!flag) && (!b)) {
            
        }
        else flag = 1;
    }

    cout << ans << " " << t * 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    return 0;
}
