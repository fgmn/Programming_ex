#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100010;

int a[N], L[N], R[N];

/*
7
2 1 4 5 1 3 3 
1 1 3 3

3
5 5 5
*/

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> stk;

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && a[stk.top()] >= a[i]) {
            R[stk.top()] = i - 1;
            stk.pop();
        }
        if (!stk.empty()) L[i] = stk.top() + 1;
        else L[i] = 0;
        stk.push(i);
    }

    while (!stk.empty()) {
        R[stk.top()] = n - 1;
        stk.pop();
    }

    for (int i = 0; i < n; i++) {
        cout << "(L, R)=(" << L[i] << ", " << R[i] << ")\n";
    }

    ll ans  = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, 1ll * a[i] * (R[i] - L[i] + 1));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
