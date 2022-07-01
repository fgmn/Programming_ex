#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
using ll = long long;
const int N = 5e4 + 5;

struct edge
{
    edge(int v, int w):v(v), w(w) {}
    int v, w;
};


ll f[N][105];
vector<edge> g[N];
int ct[N];      // 子树中关键节点数
int n, m, k;

void dfs(int x, int fa) {
    for (auto &i : g[x]) {
        if (i.v == fa) continue;
        dfs(i.v, x);
        ct[x] += ct[i.v];
        // 枚举子树中的取点个数j
        for (int j = min(k, ct[x]); j >= 0; j--) {  // 分支相当于一类物品，分支中有多个关键节点->多重背包
            for (int l = 0; l <= j && l <= ct[i.v]; l++) {  // j >= j - l
                f[x][j] = min(f[x][j], f[i.v][l] + f[x][j - l] + 1ll * l * (k - l) * i.w);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> k;

    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
        f[i][0] = 0;
    }

    int u, v, w;
    for (int i = 1; i <= m; i++) {
        cin >> u;
        ct[u] = 1;
        f[u][1] = 0;    // 当前节点为关键节点则贡献为0
    }

    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        g[u].push_back(edge(v, w));
        g[v].push_back(edge(u, w));
    }

    dfs(1, 0);
    cout << f[1][k] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
