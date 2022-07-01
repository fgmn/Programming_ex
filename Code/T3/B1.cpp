#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 标点符号和前面单词形成单词块
// 如何判断原文章的段数

bool isP(char c) {
    return !isalpha(c);
}

void solve() {
    int n, d;
    cin >> n >> d;

    string line;
    int cnt;        // 当前行字符数
    cin.ignore();   // 清空缓冲区，否则影响getline读入
    int c = 0;
    while (getline(cin, line)) {
        cout << "   ";
        cnt = 3;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            int l = word.length();
            if (cnt + l <= d) {
                cout << word << ' ';
                cnt += l + 1;
            }
            else if (cnt + l == d + 1) {
                if (isP(word[l - 1])) {
                    cout << word;
                    cnt += l;
                }
                else goto TAG;
                // goto TAG;
            }
            else {
                TAG:cout << "\n";
                cout << word << ' ';
                cnt = l + 1;
            }
        }
        if (c++ < n) cout << "\n";
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("B.out", "w", stdout);

    solve();
    return 0;
}