#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

const int N = 105;
int f[N][N];

void solve() {
    string s;
    cin >> s;

    int n = s.length();
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            f[i][j] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= n; i++) f[i][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            int r = i + j - 1;  // 考虑区间[j, k]
            for (int k = j; k < r; k++) {
                f[j][r] = min(f[j][r], f[j][k] + f[k + 1][r]);
            }
            if (s[j - 1] == '(' && s[r - 1] == ')') {
                f[j][r] = min(f[j][r], f[j + 1][r - 1]);
            }
            if (s[j - 1] == '[' && s[r - 1] == ']') {
                f[j][r] = min(f[j][r], f[j + 1][r - 1]);
            }
        }
    } 

    cout << f[1][n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
