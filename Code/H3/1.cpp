#include<bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    int n, k;
    cin >> n >> k;

    vector<bool> vis(n + 1, false);

    ll Cnt = n, j = 1;

    while (Cnt > 1) {
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (j % 10 == k || !(j % k)) {
                    vis[i] = 1;
                    Cnt--;
                    if (Cnt == 1) break;
                }
                j++;
            }
        }
    }

    int ans;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
