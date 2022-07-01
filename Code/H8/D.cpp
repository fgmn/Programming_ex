#include<iostream>
#include<vector>
#include<algorithm>
#define N 1000010
using namespace std;
using ll = long long;

// SCC 缩点

vector<int> g1[N], g2[N], g[N];
bool vis[N];
int dfn[N], scc[N], sz[N];
int cnt, tot;
int d[N];

void dfs(int u) {
    vis[u] = 1;
    for (int v : g1[u]) {
        if (!vis[v]) dfs(v);
    }
    dfn[++cnt] = u;
}

void dfs1(int u, int c) {
    scc[u] = c;
    for (int v : g2[u]) {
        if (!scc[v]) dfs1(v, c);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    for (int i = n; i > 0; i--) {
        if (!scc[dfn[i]]) dfs1(dfn[i], ++tot);
    }

    for (int i = 1; i <= n; i++) {
        sz[scc[i]]++;
        for (int j : g1[i]) {   // 对原图进行缩点
            if (scc[j] != scc[i]) {
                g[scc[i]].push_back(scc[j]);
            }
        }
    }

    for (int i = 1; i <= tot; i++) {
        sort(g[i].begin(), g[i].end());
        vector<int>::iterator newEnd;
        newEnd = unique(g[i].begin(), g[i].end());
        g[i].erase(newEnd, g[i].end());
        for (int v : g[i]) d[v]++;
    }

    int ans = 0;
    for (int i = 1; i <= tot; i++) {
        if (!d[i]) {
            ans++;
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
