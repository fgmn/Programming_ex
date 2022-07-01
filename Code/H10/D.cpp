#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
ll a[N];
int n;
int ans[N];
pair<int, int> b[N];

/*
6
1 1
2 1
3 3
4 4
5 5
1 2

2
1 0
0 1
*/

//单点更新
void update(int x, ll y)
{
    while (x <= N)
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

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> b[i].first >> b[i].second;
    }
    
    sort(b + 1, b + n + 1, cmp);

    // Z维护‘0’
    for (int i = 1; i <= n; i++) {
        int k = getsum(b[i].second + 1);
        ans[k]++;
        update(b[i].second + 1, 1);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
