#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const int N = 1005;
vector<pair<int, int> > s[105];
int f[N];

void solve() {
    int n, v;
    cin >> n >> v;

    int w, c, k;
    for (int i = 1; i <= n; i++) {
        cin >> w >> c >> k;
        s[k].push_back({w, c});
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = v; j > 0; j--) {
            for (auto k : s[i]) {
                if (j >= k.first)
                    f[j] = max(f[j], f[j - k.first] + k.second);
            }
        }
    }
    cout << f[v] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
