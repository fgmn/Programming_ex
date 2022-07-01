#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll score = 0;
    int a, pre = 2;

    while (cin >> a) {
        if (!a) break;

        if (a == 2) {
            score += pre;
            pre += 2;
        }
        else if (a == 1) {
            score += 1;
            pre = 2;
        }
    }

    cout << score << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
