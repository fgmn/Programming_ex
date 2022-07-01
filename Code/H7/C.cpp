#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

// 负权环路

vector<pair<int, int> > g[505];
int cnt[505], dis[505];
bool vis[505];
int n, m, w;

void spfa(int s) {
    for (int i = 1; i <= n; i++) {
        vis[i] = cnt[i] = 0;
        dis[i] = INT32_MAX;
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
            if (dis[i.second] > dis[u] + i.first) {
                dis[i.second] = dis[u] + i.first;
                cnt[i.second] = cnt[u] + 1;
                if (cnt[i.second] >= n) {
                    cout << "YES\n";
                    return;
                }
                if (!vis[i.second]) {
                    vis[i.second] = 1;
                    Q.push(i.second);
                }
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int F; cin >> F;
    while (F--) {
        
        cin >> n >> m >> w;
        
        for (int i = 1; i <= n; i++) {
            g[i].clear();
        }

        int s, e, t;
        for (int i = 1; i <= m; i++) {
            cin >> s >> e >> t;
            g[s].push_back({t, e});
            g[e].push_back({t, s});
        }

        for (int i = 1; i <= w; i++) {
            cin >> s >> e >> t;
            g[s].push_back({-t, e});
        }

        spfa(1);
    }

    return 0;
}
