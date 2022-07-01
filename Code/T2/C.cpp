#include<iostream>
using namespace std;
using ll = long long;

int a[10010], b[10010], Num[10010];
ll pre[10010];
// bool vis[10010];
int vis[10010];

int Cnt;

/*
3 5
1 2 3
1 3 2 3 1 // 2 3 3 2
*/

// 维护区间不同数之和

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        // if (!vis[b[i]])
            pre[i] = pre[i - 1] + a[b[i]];
        // if (vis[b[i]]) continue;
        // vis[b[i]] = 1;
        // Num[b[i]] = ++Cnt;
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        if (vis[b[i]]) {
            ans += pre[i - 1] - pre[vis[b[i]]];
        }
        else {
            ans += pre[i - 1];
        }
        vis[b[i]] = i;
    }
    cout << ans << '\n';
    return 0;
}
