#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
struct edge
{
    ll v, t1, t2;
    edge(int v, int t1, int t2):v(v), t1(t1), t2(t2) {}
};

vector<edge> g[N];
ll dis[N];
bool vis[N];
int n, m;

// 决策：直接走或者等1s后走

void spfa(int s) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        dis[i] = LONG_LONG_MAX;
    }

    dis[s] = 0;
    vis[s] = true;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = false;

        for (auto i : g[u]) {
            int t;
            if (dis[u] % 2 == 0) {
                t = min(i.t1, i.t2 + 1);              
            }
            else {
                t = min(i.t1 + 1, i.t2); 
            }
            if (dis[i.v] > dis[u] + t) {
                dis[i.v] = dis[u] + t;
                if (!vis[i.v]) {
                    vis[i.v] = 1;
                    Q.push(i.v);
                }
            }              
        }
    }

    cout << dis[n] << '\n';
}


void solve() {
    cin >> n >> m;

    int u, v, t1, t2;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> t1 >> t2;
        if (t1 == -1) t1 = INT32_MAX;
        if (t2 == -1) t2 = INT32_MAX;
        g[u].push_back(edge(v, t1, t2));
        g[v].push_back(edge(u, t1, t2));
    }

    spfa(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
