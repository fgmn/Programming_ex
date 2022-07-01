#include<iostream>
#include<set>
using namespace std;
using ll = long long;

/*
7
abcdcba
*/
set<char> a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // O(n^2)
    a.insert('a');
    a.insert('e');
    a.insert('i');
    a.insert('o');
    a.insert('u');

    int n; cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (a.count(s[i])) s[i] = 'a';
    }
    // cout << s << '\n';

    int ans = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i && i + j < n; j++) {
            if (s[i - j] != s[i + j]) {
                ans = max(ans, 2 * j - 1);   // [i - j + 1, i + j - 1]  
                break;
            }

            if (i == j || i + j == n - 1) {
                ans = max(ans, 2 * j + 1);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i && i + j - 1 < n; j++) {
            if (s[i - j] != s[i + j - 1]) {
                ans = max(ans, 2 * j - 2);
                break;
            }

            if (i == j || i + j == n) {
                ans = max(ans, 2 * j);
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}
