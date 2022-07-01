#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
int a[N], h[N], f;
int n;

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int y) {
    h[x] = y;   // ?
    while (x <= N) {
        // 重新求解区间(x - lowbit(x), x]最大值
        for (int i = 1; i < lowbit(x); i <<= 1) {
            h[x] = max(h[x], h[x - i]);
        }
        x += lowbit(x);
    }
}

int query(int y)
{
	int ans = 0;
	while (y > 0)
	{
		ans = max(a[y], ans);
		y--;
		for (; y - lowbit(y) > 0; y -= lowbit(y))
			ans = max(h[y], ans);
	}
	return ans;
}
// a[k]:以k为末尾元素的LIS长度

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    int ans = 0, k;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        f = query(k - 1) + 1;
        ans = max(ans, f);
        a[k] = max(a[k], f);
        update(k, a[k]);
    }
    cout << ans << '\n';
    return 0;
}
