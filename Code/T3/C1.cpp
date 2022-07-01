#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2005;

int psum[N][N];
int Ans = INT32_MIN;
// ll -> int

int cal(int x, int y, int r) {
    int res = 0;
    for (int i = -r + 1; i <= r - 1; i++) {
        res += psum[x + i][y + r - 1 - abs(i)] - psum[x + i][y - r + abs(i)];
    }
    return res;
}

void solve() {
    int n, m, r, h;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> h;
            psum[i][j] = psum[i][j - 1] + h;
        }
    }

    for (int i = r; i <= n + 1 - r; i++) {
        for (int j = r; j <= m + 1 - r; j++) {
            Ans = max(Ans, cal(i, j, r));
        }
    } 
    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
