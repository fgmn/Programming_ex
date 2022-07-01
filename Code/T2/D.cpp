#include<iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a, b;
        for (int i = 1; i <= n; i++) {
            cin >> a;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a;
        }
        for (int i = 1; i < n; i++) {
            cin >> a >> b;
        }
        // cout << "NO\n";
        if (n % 4 == 0) cout << "YES\n";
        else cout << "NO\n";

    }
    return 0;
}
