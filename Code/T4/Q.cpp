#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N];

void solve() {
    int n; cin >> n;

    int m = 0, mL = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > m) m = a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == m) {
            cnt++;
        }
        else {
            mL = max(mL, cnt);
            cnt = 0;
        }
    }
    mL = max(mL, cnt);
    cout << m << ' ' << mL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
