#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 105;
int a[N], f[10010];

void solve() {
    int n, x;
    cin >> n >> x;

    memset(f, 0x3f, sizeof f);
    f[0] = 0;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= 0; j--) {
            for (int k = 0; k <= j / a[i]; k++) {
                f[j] = min(f[j], f[j - k * a[i]] + k);
            }
        }
    }
    cout << f[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
