#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int N, A, B;
int K[205];
bool vis[205];
queue<pair<int, int> > Q;

void solve() {
    cin >> A >> B;

    for (int i = 1; i <= N; i++) {
        cin >> K[i];
    }

    if (A == B) {
        cout << "0\n";
        return;
    }

    while (!Q.empty())
        Q.pop();
    
    vis[A] = 1;
    Q.push({A, 0});
    

    while (!Q.empty()) {
        auto Now = Q.front();
        Q.pop();

        int f = Now.first;

        if (f + K[f] == B || f - K[f] == B) {
            cout << Now.second + 1 << '\n';
            return;
        }
        if (f - K[f] >= 1 && !vis[f - K[f]]) {
            vis[f - K[f]] = 1;
            Q.push({f - K[f], Now.second + 1});
        }
        if (f + K[f] <= N && !vis[f + K[f]]) {
            vis[f + K[f]] = 1;
            Q.push({f + K[f], Now.second + 1});
        }
    }

    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> N) {
        if (!N) break;
        memset(vis, false, sizeof vis);
        solve();
    }
    
    return 0;
}
