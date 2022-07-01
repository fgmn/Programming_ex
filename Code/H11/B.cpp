#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

vector<int> cnt(1000005);
vector<ll> f(1000005);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    int a;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        cnt[a]++;
    }
    f[1] = cnt[1];
    for (int i = 2; i <= 1e6; i++) {
        f[i] = max(f[i - 1], f[i - 2] + cnt[i] * i);
    }

    cout << f[1000000] << '\n';
    return 0;
}
