#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double a[100010];
int n, k;

bool Chk(double l) {
    int Cnt = 0;
    for (int i = 0; i < n; i++) {
        Cnt += a[i] / l;
        if (Cnt >= k) return 1;
    }
    return 0;
}

void solve() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    double l = 0, r = 1e8;

    while ((r - l) > 1e-8) {
        double mid = (l + r) / 2;
        if (Chk(mid)) {
            l = mid;
        }
        else r = mid;
    }

    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
