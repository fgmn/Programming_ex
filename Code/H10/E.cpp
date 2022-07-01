#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 输出前L个中最值 -> 查询区间最值

const int N = 2e5 + 5;
int A[N], h[N];
int n;
ll m, p;

int lowbit(int x) {
    return x & (-x);
}

// 赋值操作：A[i] = val
/*
void update(int i, int val)
{
	while (i <= m + 1)
	{
		h[i] = max(h[i], val);  // 只能应对增大赋值
		i += lowbit(i);
	}
}
*/

void update(int x, int y) {
    while (x <= m + 1) {
        h[x] = y;
        // 重新求解区间(x - lowbit(x), x]最大值
        for (int i = 1; i < lowbit(x); i <<= 1) {
            h[x] = max(h[x], h[x - i]);
        }
        x += lowbit(x);
    }
}

int query(int x, int y)
{
	int ans = 0;
	while (y >= x)
	{
		ans = max(A[y], ans);
		y--;
		for (; y - lowbit(y) >= x; y -= lowbit(y))
			ans = max(h[y], ans);
	}
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> p;

    ll a = 0, t;
    char op;
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        cin >> op >> t;
        if (op == 'Q') {
            int l = cnt - t + 1;
            if (l < 1) l = 1;
            int ans = query(l, cnt);
            a = ans;
            cout << ans << '\n';
        }
        else {
            A[++cnt] = (t + a) % p;
            update(cnt, A[cnt]);
        }
    }
    return 0;
}
