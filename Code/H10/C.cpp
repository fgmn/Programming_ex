#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
ll a[N];
int n, q; //节点总数，询问数

//单点更新
void update(int x, ll y)
{
    while (x <= n)
    {
        a[x] += y;
        x += x & (-x);
    }
}

//区间查询
ll getsum(int x)
{
    ll res = 0;
    while (x > 0)
    {
        res += a[x];
        x -= x & (-x);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        update(i, x);
    }
    
    int op, l, r;
    for (int i = 1; i <= q; i++) {
        cin >> op >> l >> r;
        if (op == 1) {
            update(l, r);
        }
        else {
            ll ans = getsum(r) - getsum(l - 1);
            cout << ans << '\n';
        }
    }
    return 0;
}
