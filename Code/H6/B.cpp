#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char A[5] = {'a', 'e', 'i', 'o', 'u'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;

    int Cnt = 0, ans = 0;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (A[j] == s[i]) {
                if (!Cnt) cout << s[i];
                Cnt++;
                break;
            }
            if (j == 4) {
                cout << s[i];
                ans = max(ans, Cnt);
                Cnt = 0;
            }
        }
    }
    ans = max(ans, Cnt);
    // cout << ans << '\n';
    return 0;
}
