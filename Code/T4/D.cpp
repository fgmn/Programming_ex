#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;
int t[N], c[N], I[N];
int ans[N];
vector<int> g[N];
int fa[N];
queue<int> Q;

void dfs(int u) {
    if (t[u] == 1) {
        ans[u] = 1;
        for (auto i : g[u]) {
            dfs(i);
            ans[u] &= ans[i];
        }
    }
    else if (t[u] == 2) {
        for (auto i : g[u]) {
            dfs(i);
            ans[u] |= ans[i];
        }
    }
    else if (t[u] == 3) {
        for (auto i : g[u]) {
            dfs(i);
            ans[u] ^= ans[i];
        }
    }
    else if (t[u] == 4) {
        for (auto i : g[u]) {
            dfs(i);
            ans[u] = 1 - ans[i];
        }
    }
    else {
        ans[u] = c[u];  // c[]: 储存输入
    }
}

bool ok;

// 是否可以一次dfs完成
// 返回是否会改变输出
// 可以向上传递必然是因为当前节点状态改变
void dfs1(int u) {
    // cout << u << ' ';
    if (fa[u] == 0) { ok = 1; return; }
    int C = 0;  // 改变之后重新计算
    int F = fa[u];  // 判断父亲节点是否改变
    if (t[F] == 1) {
        C = 1;
        for (auto i: g[F]) {
            if (i == u) C &= 1 - ans[i];
            else {
                C &= ans[i];
            }
        }
    }
    else if (t[F] == 2) {
        for (auto i: g[F]) {
            if (i == u) C |= 1 - ans[i];
            else {
                C |= ans[i];
            }
        }
    }
    else if (t[F] == 3) {
        for (auto i: g[F]) {
            if (i == u) C ^= 1 - ans[i];
            else {
                C ^= ans[i];
            }
        }
    }
    else if (t[F] == 4) {
        C = ans[u];
    }
    if (ans[F] != C) {
        dfs1(F);
    }
}

void solve() {
    int n; cin >> n;

    string s;
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (s == "AND") {
            t[i] = 1;   // 直接存储字符串？
            cin >> a >> b;
            I[a] = I[b] = 1;
            g[i].push_back(a);
            g[i].push_back(b);
            fa[a] = i;
            fa[b] = i;
        }
        else if (s == "OR") {
            t[i] = 2;
            cin >> a >> b;
            I[a] = I[b] = 1;
            g[i].push_back(a);
            g[i].push_back(b);
            fa[a] = i;
            fa[b] = i;
        }
        else if (s == "XOR") {
            t[i] = 3;
            cin >> a >> b;
            I[a] = I[b] = 1;
            g[i].push_back(a);
            g[i].push_back(b);
            fa[a] = i;
            fa[b] = i;
        }
        else if (s == "NOT") {
            t[i] = 4;
            cin >> a;
            I[a] = 1;
            g[i].push_back(a);
            fa[a] = i;
        }
        else {
            t[i] = 5;
            cin >> c[i];
            I[i] = 1;
            Q.push(i);
        }
    }

    int root;
    for (int i = 1; i <= n; i++) {
        if (!I[i]) {
            root = i;
            break;
        }
    }

    dfs(root);

    // 建立反图dfs判断该输入端改变是否会改变输出
    while (!Q.empty()) {
        int f = Q.front();
        Q.pop();
        // cout << f << ":\n";
        ok = 0;
        dfs1(f);
        // cout << '\n';

        if (ok) {
            cout << 1 - ans[root];
        }
        else {
            cout << ans[root];
        }
    }

    /*while (!Q.empty()) {
        int f = Q.front();
        Q.pop();
        c[f] = 1 - c[f];
        memset(ans, 0, sizeof ans);
        dfs(root);
        c[f] = 1 - c[f];
        cout << ans[root];
    }*/
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
