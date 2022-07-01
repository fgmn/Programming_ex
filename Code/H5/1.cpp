#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int pSum[500005][26];   // 1.3e7

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // pSum[0][s[0] - 'A']++;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            pSum[i][j] = pSum[i - 1][j] + (s[i - 1] - 'A' == j ? 1 : 0);
        }
    }

    int m, l, r;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> l >> r;
        // l--, r--;
        if (r - l + 1 < 26) {
            cout << "NO\n";
        }
        else {
            for (int j = 0; j < 26; j++) {
                if (pSum[r][j] == pSum[l - 1][j]) {
                    cout << "NO\n";
                    break;
                }
                if (j == 25) cout << "YES\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
