#include<iostream>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, y, g;
    cin >> r >> y >> g;

    int n; cin >> n;

    int k, t, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> k >> t;
        if (!k) {
            ans += t;
        }
        else if (k == 1) {
            ans += t;
        }
        else if (k == 2) {
            ans += (t + r);
        }
    }
    cout << ans << '\n';
    return 0;
}
