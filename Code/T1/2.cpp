#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int Cnt[55];

bool Chk7(int a) {
    while (a) {
        int D = a % 10;
        if (D == 7) return 1;
        a /= 10;
    }
    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1, j = 0; i <= m; i++) {
        // (j + 1): 当前报数人
        if (Chk7(i) || !(i % 7)) Cnt[j + 1]++;
        j = (j + 1) % n;
    }

    for (int i = 1; i <= n; i++) {
        cout << Cnt[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
