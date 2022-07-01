#include<iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

int a[N], tree[N << 2];
int n;

void build(int now, int l, int r) {
    if (l == r) {
        tree[now] = a[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(now * 2, l, mid);
    build(now * 2 + 1, mid + 1, r);
    tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
}

int query(int now, int l, int r, int ql, int qr) {
    int res = 0;
    if (ql <= l && qr >= r) {
        res = max(res, tree[now]);
        return res;
    }

    int mid = (l + r) >> 1;
    if (ql <= mid) {
        res = max(res, query(now * 2, l, mid, ql, qr));
    }
    if (qr > mid) {
        res = max(res, query(now * 2 + 1, mid + 1, r, ql, qr));
    }
    return res;
}

void update(int now, int l, int r, int x, int uy) {
    if (l == r) {
        tree[now] = uy;
        return;
    }

    int mid = (l + r) >> 1;
    if (x <= mid) {
        update(now * 2, l, mid, x, uy);
    }
    else {
        update(now * 2 + 1, mid + 1, r, x ,uy);
    }

    tree[now] = max(tree[now * 2], tree[now * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, p;
    cin >> m >> p;
    n = m + 1;

    ll a = 0, t;
    char op;
    int cnt = 0;

    for (int i = 1; i <= m; i++) {
        cin >> op >> t;
        if (op == 'Q') {
            int l = cnt - t + 1;
            if (l < 1) l = 1;
            int ans = query(1, 1, n, l, cnt);
            a = ans;
            cout << ans << '\n';
        }
        else {
            update(1, 1, n, ++cnt, (t + a) % p);
        }
    }
    return 0;
}
