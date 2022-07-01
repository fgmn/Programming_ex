#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
const int N = 1e4 + 10;

struct edge {
    int v, c, d;
};

int n, m, t;
vector<edge> g[N];
int dis[N];
bool vis[N];
priority_queue<pair<int, int> > Q;

void Dijkstra(int T) {
    for (int i = 1; i <= n; i++) {
        dis[i] = INT32_MAX;
        vis[i] = false;
    }
    while (!Q.empty()) Q.pop();

    dis[1] = 0;
    Q.push({0, 1});

    while (!Q.empty()) {
        pair<int, int> e = Q.top();
        int u = e.second;
        if (u == n) return;
        Q.pop();

        if (vis[u]) continue;
        vis[u] = true;

        int sz = g[u].size();
        for (int i = 0; i < sz; i++) {
            int V = g[u][i].v, L = g[u][i].d;
            if (g[u][i].c < T) continue;
            if (vis[V] == 0 && dis[V] > dis[u] + L) {
                dis[V] = dis[u] + L;
                Q.push({-dis[V], V});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int X; cin >> X;
    while (X--) {
        
        cin >> n >> m >> t;

        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }

        int a, b, c, d;
        for (int i = 1; i <= m; i++) {
            cin >> a >> b >> c >> d;
            g[a].push_back({b, c, d});
            g[b].push_back({a, c, d});
        }

        int ans;
        int l = 1, r = 1e7;
        while (l <= r) {
            int mid = (l + r) >> 1;
            Dijkstra(mid);
        
            if (dis[n] <= t) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
