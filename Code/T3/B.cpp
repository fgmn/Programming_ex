#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 标点符号和前面单词形成单词块
// 如何判断原文章的段数

void solve() {
    int n, d;
    cin >> n >> d;

    string line;
    getline(cin, line);
    int cnt = 3;
    cout << "   ";
    for (int i = 1; i <= n; i++) {
        getline(cin, line);
        stringstream ss(line);
        string w;
        while (ss >> w) {
            int l = w.length();
            if (cnt + l <= d) {
                cout << w << ' ';
                cnt += l + 1;
            }
            else if (cnt + l == d + 1 && (!isalpha(w[l - 1]))) {
                cout << w;
                cnt += l;
            }
            else {
                cout << '\n';
                cout << w << ' ';
                cnt = l + 1;
            }
        }
        if (i < n) cout << "\n   ";
        cnt = 3;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 重定向输入时getline会有问题
    // freopen("B.out", "w", stdout);

    solve();
    return 0;
}