#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, Size;
unsigned int C;
vector<pair<int, int> > mp;
bool Row[10], Col[10];

void dfs(int cnt, int now) {
    if (cnt == k) {
        C++;
        return;
    }

    if (now < Size) {
        int x = mp[now].first;
        int y = mp[now].second;

        if (!Row[x] && !Col[y]) {
            Row[x] = 1;
            Col[y] = 1;

            dfs(cnt + 1, now + 1);

            Row[x] = 0;
            Col[y] = 0;
        }

        dfs(cnt, now + 1);
    }
}

void solve() {
    char c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c;
            if (c == '#') {
                mp.push_back({i, j});
            }
        }
    }

    Size = mp.size();

    if (k > n) {
        cout << "0\n";
        return;
    }

    dfs(0, 0);

    cout << C << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> k) {
        if (n == -1) break;

        C = 0;
        for (int i = 1; i <= n; i++) {
            Row[i] = 0;
            Col[i] = 0;
        }
        mp.clear();
        
        solve();
    }

    return 0;
}
