#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

// a = a - 1
// k == 1: cb - ca <= c
// -> cb <= ca + c
// 根据上述松弛公式得连边 a -> b
// k == 2: cb - ca >= c
// k == 3: cb - ca <= c - 1
// k == 4: cb - ca >= c + 1
// max(cn)
// 0 <= dis[i] - d[i - 1] <= 1

const int N = 1010;
int n, m;
int dis[N], cnt[N];
vector<pair<int, int> > g[N];
bool vis[N];

void spfa(int s) {
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        dis[i] = INT32_MAX;
        cnt[i] = 0;
    }

    dis[s] = 0;
    vis[s] = true;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;

        for (auto i : g[u]) {
            int v = i.first, l = i.second;
            if (dis[v] > dis[u] + l) {
                dis[v] = dis[u] + l;
                cnt[v] = cnt[u] + 1;

                if (cnt[v] >= n) {
                    cout << "impossible\n";
                    return;
                }

                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }

    if (dis[n] == INT32_MAX) {
        cout << "impossible\n";
    }
    else cout << dis[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int k, a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> k >> a >> b >> c;
        a--;
        switch (k) {
            case 1: g[a].push_back({b, c});
                    break;
            case 2: g[b].push_back({a, -c});
                    break;
            case 3: g[a].push_back({b, c - 1});
                    break;
            case 4: g[b].push_back({a, -c - 1});
                    break;
            case 5: g[a].push_back({b, c});
                    g[b].push_back({a, -c});
                    break;
        }
    }

    for (int i = 1; i <= n; i++) {
        g[i - 1].push_back({i, 1});
        g[i].push_back({i - 1, 0});
    }

    spfa(0);
    return 0;
}
