#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

ll f[15][(1 << 15)];    
// f[i][j]: 前i行且第i行的状态为j时的方案数
// 注意i * w为奇数时没有实际意义，最后一行不全部为0
int h, w;

// 检查是否连续的‘0’均为偶数个
bool chk(int a) {
    int cnt = 0;
    for (int i = 0; i < w; i++) {
        if (a & (1 << i)) {
            if (cnt & 1) return false;
            cnt = 0;
        }
        else cnt++;
    }
    if (cnt & 1) return false;
    return true;
}

void solve() {
    
    cin >> h >> w;

    // 只有奇数个方格显然无解
    if (h * w % 2) {
        cout << 0 << '\n';
        return;
    }
    
    // 假设第0行的状态为0，即所有长方形水平放置
    f[0][0] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < (1 << w); j++) {        // 枚举当前行状态
            for (int k = 0; k < (1 << w); k++) {    // 枚举上一行状态
                if (j & k) continue;                // 出现上1下1的情况不合法
                if (!chk(j | k)) continue;          // 有连续奇数'0'状态不合法
                f[i][j] += f[i - 1][k];
            }
        }
    }
    
    cout << f[h][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
