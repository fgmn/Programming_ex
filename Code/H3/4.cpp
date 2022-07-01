#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int a[25];
int Ans;
int n, k;

bool prime(int n)
{
    if (n == 1) return false;
    if (n == 2) return true;

	for(int i = 2; i * i <= n; i++)
	    if (n % i == 0) return false;

	return true;
}

// x <= 5e6

void dfs(int cnt, int sum, int now) {
    if (cnt == k) {
        // cout << sum << '\n';
        if (prime(sum)) Ans++;
        return;
    }

    if (now <= n) {
        dfs(cnt, sum, now + 1);
        dfs(cnt + 1, sum + a[now], now + 1);
    }
}

void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    dfs(0, 0, 1);

    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
