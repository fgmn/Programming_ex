#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2005;

int h[N][N];
bool vis[N][N];
int n, m, r;

// 关系具有对称性
// 4e6
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct z
{
    int first, second, r;
    z(int a, int b, int c):first(a), second(b), r(c) {};
};


int bfs(int i, int j, int r) {
    int res = 0;
    queue<z> q;

    vis[i][j] = 1;
    q.push(z(i, j, r));
    res += h[i][j];

    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (!top.r) continue;
        for (int k = 0; k < 4; k++) {
            int nx = top.first + dx[k];
            int ny = top.second + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if (!vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push(z(nx, ny, top.r - 1));
                res += h[nx][ny];
            }
        }
    }
    return res;
}

void solve() {
    
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> h[i][j];
        }
    }

    int Ans = INT32_MIN;
    for (int i = 1; i <= n; i++) {
        if (i < r || i + r - 1 > n) continue;
        for (int j = 1; j <= m; j++) {
            if (j < r || j + r - 1 > m) continue;
            memset(vis, 0, sizeof vis);
            Ans = max(Ans, bfs(i, j, r - 1));
        }
    }    
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
