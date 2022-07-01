#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int a[N], h[N], sz[N];
int p[N], q[N];
int f[N];
vector<int> g[N];
bool vis[N];

// p[i] - q[i] = h[i]
// p[i] + q[i] = sz[i]
// p[i] = (h[i] + sz[i]) / 2 >= 0
// q[i] >= 0
// q[i] >= sum(q[son])

void dfs(int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (vis[v]) continue;
        f[v] = u;
        dfs(v);
        sz[u] += sz[v];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        sz[i] = a[i];
        f[i] = 0;
        g[i].clear();
    }
    for (int i = 1; i <= n; i++) cin >> h[i];

    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(vis, false, sizeof vis);
    dfs(1);
    for (int i = 1; i <= n; i++) {
        p[i] = (sz[i] + h[i]) / 2;
        q[i] = (sz[i] - h[i]) / 2;
        if (p[i] < 0 || q[i] < 0 || (sz[i] ^ h[i]) & 1) {
            cout << "NO\n";
            return;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        int sp = 0;
        for (int s : g[i]) {
            if (s == f[i]) continue;
            sp += p[s];
        }
        if (sp > p[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
