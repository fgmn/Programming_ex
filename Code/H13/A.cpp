#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
using ll = long long;

const int N = 205;

int f[N][N];    // f[i][j]: 代表合并区间[i, j]石子的最小花费
int a[N], p[N]; // p为前缀和，快速查询区间和

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    // 由于是环形放置，可以构造两倍长数组，遍历f[i][i+n-1]（1<=i<=n）取最小即可
    for (int i = n + 1; i <= 2 * n; i++) {
        p[i] = p[i - 1] + a[i - n];
    }

    memset(f, 0x3f, sizeof f);
    // 初始化长度为0的区间费用为0，其他为无穷大
    for (int i = 1; i <= 2 * n; i++) f[i][i] = 0;

    for (int i = 2; i <= n; i++) {  // 第一维枚举长度，长度由小增大，保证递推的正确性
        for (int j = 1; j <= 2 * n - i + 1; j++) {  // 枚举左边界
            int r = i + j - 1;                      // 计算右边界
            for (int k = j; k < r; k++) {           // 枚举分割线（当前状态可能的转移）
                f[j][r] = min(f[j][r], f[j][k] + f[k + 1][r] + p[r] - p[j - 1]);
            }
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, f[i][i + n - 1]);
    }
    cout << ans << '\n';

    // 最大值类同
    memset(f, 0, sizeof f);

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 2 * n - i + 1; j++) {  // 枚举左端点
            int r = i + j - 1;
            for (int k = j; k < r; k++) {
                f[j][r] = max(f[j][r], f[j][k] + f[k + 1][r] + p[r] - p[j - 1]);
            }
        }
    }
    ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, f[i][i + n - 1]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
