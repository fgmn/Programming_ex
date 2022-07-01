#include<bits/stdc++.h>
using namespace std;
using ll = long long;

set<pair<int, int> > Set, Set2;
int Step[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool Reach[10005][10005];

// O(Sum(step) * log(k))
// O(Sum(step) + k)

void solve() {
    int n, m, k;
    cin >> n >> m;
    cin >> k;

    int x, y, ans = 0, sumStep = 0;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        Set.insert({x, y});
    }

    int t;
    cin >> t;

    int cX = 1, cY = 1;
    if (Set.count({1, 1})) {
        ans++;
        Set.erase({1, 1});
    }

    char Dir;
    int step, D;

    while (t--) {
        cin >> Dir >> step;

        if (Dir == 'W') D = 0;
        else if (Dir == 'A') D = 1;
        else if (Dir == 'S') D = 2;
        else if (Dir == 'D') D = 3; 

        for (int i = 1; i <= step; i++) {
            cX += Step[D][0];
            cY += Step[D][1];
            if (!Reach[cX][cY]) {
                Reach[cX][cY] = 1;
                sumStep++;
                if (sumStep >= n * m)
                    goto TAG;
                // if (Set.count({cX, cY}) == 1) {
                //     Set.erase({cX, cY});
                //     ans++;
                //     if (ans == k) break;
                // }
            }

        }
    }

    TAG:for (auto i : Set) {
        if (Reach[i.first][i.second])
            ans++;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    solve();
    return 0;
}
