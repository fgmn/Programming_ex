#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int a[N], f[N][8];

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') a[i + 1] += 1;
    }
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') a[i + 1] += 2;
    }

    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') a[i + 1] += 4;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            if (j & a[i]) continue;

            // 转移
            // 忽略对上一行状态的限制 -> 可以尝试初始化成较大负数
            int m = 0;
            if (j == 0) {
                for (int k = 0; k < 8; k++) {
                    m = max(m, f[i - 1][k]);
                }
                f[i][0] = m;
            }
            else if (j == 1) {
                if (a[i - 1] & 3) continue;
                f[i][1] = max(f[i - 1][0], f[i - 1][4]) + 1;
            }
            else if (j == 2) {
                if ((a[i - 1] & 3) == 0) {
                    m = max(f[i - 1][0], f[i - 1][4]);
                    f[i][2] = m + 1;
                }
                m = 0;
                if ((a[i - 1] & 6) == 0) {
                    m = max(f[i - 1][0], f[i - 1][1]);
                    f[i][2] = max(f[i][2], m + 1);
                }
            }
            else if (j == 3) {
                if ((a[i - 1] & 1) == 0) {
                    m = max(f[i - 1][0], f[i - 1][2]);
                    m = max(m, f[i - 1][4]);
                    m = max(m, f[i - 1][6]);
                    f[i][3] = m + 1;
                }
                m = 0;
                if ((a[i - 1] & 2) == 0) {
                    m = max(f[i - 1][0], f[i - 1][1]);
                    m = max(m, f[i - 1][4]);
                    f[i][3] = max(f[i][3], m + 1);
                }
            }
            else if (j == 4) {
                if (a[i - 1] & 6) continue;
                f[i][4] = max(f[i - 1][0], f[i - 1][1]) + 1;
            }
            else if (j == 5) {
            }
            else if (j == 6) {
                if ((a[i - 1] & 2) == 0) {
                    m = max(f[i - 1][0], f[i - 1][1]);
                    m = max(m, f[i - 1][4]);
                    f[i][6] = m + 1;
                }
                m = 0;
                if ((a[i - 1] & 4) == 0) {
                    m = max(f[i - 1][0], f[i - 1][1]);
                    m = max(m, f[i - 1][2]);
                    m = max(m, f[i - 1][3]);
                    f[i][6] = max(f[i][6], m + 1);
                }
            }
            else if (j == 7) {
                if (a[i - 1] & 7) continue;
                f[i][7] = f[i - 1][0] + 2;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        ans = max(ans, f[n][i]);
    }
    cout << ans << '\n';

    /*for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            cout << f[i][j] << ' ';
        }
        cout << '\n';
    }*/
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}

/*
6
......
.#..#.
......

6
..####
.#.##.
##....
*/