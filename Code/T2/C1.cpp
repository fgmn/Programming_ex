#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
using ll = long long;


int a[10010], b[10010];
bool vis[10010];
bool vis2[10010];

/*
3 5
1 2 3
1 3 2 3 1 // 2 3 3 2
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    int cnt;
    ll ans = 0;
    for (int i = 1; i <= m; i++) {      // b[i]
        if(vis2[b[i]]) continue;
        vis2[b[i]] = 1;
        memset(vis, 0, sizeof vis);
        cnt = 0;
        for (int j = i + 1; j <= m; j++) {
            if (b[j] == b[i]) {
                ans += a[b[i]] * cnt;
                memset(vis, 0, sizeof vis);
                cnt = 0;
                continue;
            }
            if (vis[b[j]]) continue;
            vis[b[j]] = true;
            cnt++;
        }
        ans += a[b[i]] * cnt;
        // cout << "c: " << ans << ' ' << cnt << '\n';
    }
    cout << ans << '\n';
    return 0;
}
