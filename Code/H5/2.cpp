#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int Cnt[26];

bool C() {
    for (int i = 0; i < 26; i++) {
        if (!Cnt[i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = n;
    for (int i = 0, j = 0; i < n; i++) {    // [j, i]
        ++Cnt[s[i] - 'A'];
        while (C()) {
            ans = min(ans, i - j + 1);
            --Cnt[s[j] - 'A'];
            j++;
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
