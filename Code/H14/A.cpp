#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const int N = 1e5 + 5;
vector<int> g[N];
int far[N], diam[N];
ll cntf[N], cntd[N];

void dfs(int x, int f) {
    cntf[x] = 1;    // 节点最大深度数至少为1（叶子节点）
    for (auto &i : g[x]) {
        if (i == f) continue;
        dfs(i, x);

        if (far[i] + 1 > far[x]) {
            far[x] = far[i] + 1;
            cntf[x] = cntf[i];
        }
        else if (far[i] + 1 == far[x]) {
            cntf[x] += cntf[i];
        }
    }

    // 直径从根节点到叶子
    diam[x] = far[x];
    cntd[x] = cntf[x];

    // 直径不经过子树根节点
    for (auto &i : g[x]) {
        if (i == f) continue;
        if (diam[i] > diam[x]) {
            diam[x] = diam[i];
            cntd[x] = cntd[i];
        }
        else if (diam[i] == diam[x]) {
            cntd[x] += cntd[i];
        }
    }

    // 直径经过子树根节点
    if ((f == 0 && g[x].size() < 2) || (f != 0 && g[x].size() < 3)) return;

    int m1, m2;     // 子树深度的最大、次大值
    m1 = m2 = 0;
    
    for (auto &i : g[x]) {
        if (i == f) continue;
        if (far[i] + 1 > m2) {
            m2 = far[i] + 1;
        }
        if (m2 > m1) swap(m1, m2);
    }

    ll cntn = 0;    // 直径经过根节点的方案数
    if (m1 == m2) {
        ll cnt = 0;
        for (auto &i : g[x]) {
            if (i == f) continue;
            if (far[i] + 1 == m1) {
                cntn += cnt * cntf[i];
                cnt += cntf[i];
            }
        }
    }
    else {
        ll cnt1, cnt2;
        cnt1 = cnt2 = 0;
        for (auto &i : g[x]) {
            if (i == f) continue;
            if (far[i] + 1 == m1) {
                cnt1 += cntf[i];
            }
            if (far[i] + 1 == m2) {
                cnt2 += cntf[i];
            }
        }
        cntn = cnt1 * cnt2;
    }

    if (m1 + m2 > diam[x]) {
        diam[x] = m1 + m2;
        cntd[x] = cntn;
    }
    else if (m1 + m2 == diam[x]) {
        cntd[x] += cntn;
    }
}

// 1e5 * 1e5
void solve() {
    int n;
    cin >> n;

    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << diam[1] << ' ' << cntd[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
