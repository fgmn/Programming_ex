#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;

bool vis[N];
int dis[N], ans[N];
vector<int> G[N];

void dfs(int u) {
    for (int v : G[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            dis[v] = dis[u] + 1;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    int a, b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }

    vis[1] = 1;
    dfs(1);

    int P, Q, l = 0;  // 直径PQ
    for (int i = 1; i <= n; i++) {
        if (dis[i] > l) {
            l = dis[i];
            Q = i;
        }
        dis[i] = vis[i] = 0;
    }

    vis[Q] = 1;
    dfs(Q);
    l = 0;
    for (int i = 1; i <= n; i++) {
        if (dis[i] > l) {
            l = dis[i];
            P = i;
        }
        ans[i] = max(ans[i], dis[i]);
        dis[i] = vis[i] = 0;
    }

    vis[P] = 1;
    dfs(P);
    for (int i = 1; i <= n; i++) {
        ans[i] = max(ans[i], dis[i]);
        cout << ans[i] << ' ';
    }

    return 0;
}
