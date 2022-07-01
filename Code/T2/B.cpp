#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

// 1e10
vector<int> a(1000010);
// sum / 3
// 2 * sum / 3
// [1, i] [i + 1, j] [j + 1, n]

/*
9
1 5 -6 7 9 -16 0 -2 2
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    ll sum = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];

    if (sum % 3) cout << "0\n";
    else {
        ll b = 0, c = 0;
        for (int i = 1; i < n; i++) {
            b += a[i];
            if (b == sum * 2 / 3) {
                ans += c;
            }
            if (b == sum / 3) c++;
        }
        cout << ans << '\n';
    }

    return 0;
}
