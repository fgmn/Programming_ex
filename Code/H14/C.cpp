#include<iostream>
#include<vector>
#include<deque>
#include<climits>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> sum(n + 1);

    int a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    deque<ll> q;    // 单调队列维护区间最小值
    ll ans = LONG_LONG_MIN;
    for (int i = 1; i <= n; i++) {
        while ((!q.empty()) && sum[q.back()] >= sum[i]) {
            q.pop_back();
        }
        while ((!q.empty()) && i - m > q.front()) {
            q.pop_front();
        }
        q.push_back(i);
        ans = max(ans, sum[i] - sum[q.front()]);
    }
    cout << ans;
    return 0;
}
