#include<iostream>
using namespace std;
using ll = long long;

const int N = 5005;
int w[N], c[N];
int f[N][N];

void solve() {
    int n, v;
    cin >> n >> v;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            for (int k = 0; k <= v / w[i]; k++) {
                if (j >= w[i] * k)
                    f[i][j] = max(f[i][j], f[i - 1][j - w[i] * k] + c[i] * k);
                else break;
            }
        }
    }
    cout << f[n][v] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
