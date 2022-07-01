#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int fa[100010];

int Find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = Find(fa[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) fa[i] = i;

    int a, b, Cnt = 1;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        int f1 = Find(a), f2 = Find(b);
        if (f1 != f2) {
            Cnt++;
            fa[f1] = f2;
        }
        cout << n - Cnt << '\n';
    }
    return 0;
}
