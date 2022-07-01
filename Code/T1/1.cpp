#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
int a[505][505];
int Step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool Chk(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nX = x + Step[i][0];
        int nY = y + Step[i][1];
        if (nX >= 1 && nX <= n && nY >= 1 && nY <= m) {
            if (a[nX][nY] >= a[x][y]) return 0;
        }
    }
    
    return 1;
}

void solve() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += Chk(i ,j);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
