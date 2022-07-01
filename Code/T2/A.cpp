#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

// 1e10
vector<int> a(1000010);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll sum = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];

    if (sum & 1) cout << "0\n";
    else {
        ll b = 0;
        for (int i = 1; i < n; i++) {
            b += a[i];
            if (b == sum / 2) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
