#include<iostream>
#include<algorithm>
#define qmin(a, b) a > b ? b : a
using namespace std;
using ll = long long;

int a[1000005][3];
ll f[1000005][3];
// -1e6 1e6 -1e6 ... 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[j][i];
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            ll m = INT64_MAX;
            for (int k = 0; k < 3; k++) {
                m = qmin(m, f[i - 1][k] + abs(a[i - 1][k] - a[i][j]));
            }
            f[i][j] = m;
        }
    }

    ll ans = INT64_MAX;
    for (int i = 0; i < 3; i++) {
        ans = qmin(ans, f[n][i]);
    }
    cout << ans << '\n';
    return 0;
}
