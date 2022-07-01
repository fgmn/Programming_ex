#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;

struct edge
{
    int l, x, y;
    edge(int l, int x, int y):l(l), x(x), y(y) {}
    bool operator < (const edge &a) const {
        return l > a.l;
    }
};

int fa[N];
priority_queue<edge> Q;

int Find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = Find(fa[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    int n, m, p;
    cin >> n >> m >> p;

    for (int i = 1; i <= n + 1; i++) fa[i] = i;

    int a, b, c;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        Q.push({c, a, b});
    }

    // 源点
    for (int i = 1; i <= n; i++) {
        Q.push({p, i, n + 1});
    }

    ll sum = 0;
    int Cnt = 1;
    while (!Q.empty()) {
        edge top = Q.top();
        Q.pop();
        int fx = Find(top.x), fy = Find(top.y);
        if (fx != fy) {
            fa[fx] = fy;
            sum += top.l;
            Cnt++;
            if (Cnt == n + 1) break;
        }
    }

    cout << sum << '\n';
    return 0;
}
