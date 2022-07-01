#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

ll d[25][100005];
int pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
/*
a0 a1 a2 a3 a4
d1 = a1
d4 = a4 - a3
*/

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % Mod;
        a = a * a % Mod;
        b /= 2;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int l, r, c, b;
    for (int i = 1; i <= m; i++) {
        cin >> l >> r >> c >> b;
        for (int j = 0; j < 25; j++) {
            if (!(c % pr[j])) {
                d[j][r + 1] -= b;
                d[j][l] += b;   
                c /= pr[j];
                j--;          
            }
        }

    }

    ll p = 0, Min, ans = 1;
    for (int i = 0; i < 25; i++) {
        Min = LONG_LONG_MAX;
        p = 0;
        for (int j = 1; j <= n; j++) {
            p += d[i][j];
            // cout << p << " ";
            Min = min(Min, p);
        }
        // cout << '\n';
        ans = ans * qpow(pr[i], Min) % Mod;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
