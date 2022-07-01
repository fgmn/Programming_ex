#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

vector<pair<int, int> > g1[N], g2[N];
int cnt[N], dis[N];
bool vis[N];
int n, m, w;

void spfa(int s, vector<pair<int, int> > g[N]) {
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
                    // cout << "YES\n";
                    return;
                }
                if (!vis[i.second]) {
                    vis[i.second] = 1;
                    Q.push(i.second);
                }
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int F; cin >> F;
    while (F--) {
        
        cin >> n >> m;
        
        for (int i = 1; i <= n; i++) {
            g1[i].clear();
            g2[i].clear();
        }

        int s, e, t;
        for (int i = 1; i <= m; i++) {
            cin >> s >> e >> t;
            g1[s].push_back({t, e});
            g2[e].push_back({t, s});
        }

        spfa(1, g1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += dis[i];
        }

        spfa(1, g2);
        for (int i = 1; i <= n; i++) {
            ans += dis[i];
        }
        cout << ans << '\n';
    }

    return 0;
}
