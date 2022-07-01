#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const string op = "OpId #";
int Cnt = 1;

// 置顶、喜爱度
// 窗口次序

set<int> s;
int topWin = INT32_MAX;
map<int, ll> mp;
deque<int> Q;

// O(5 * n * n)

void solve() {
    int n;
    cin >> n;

    string str;
    ll u;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        if (str == "Add") {
            cin >> u;
            if (s.count(u)) {
                cout << op << Cnt++ << ": same likeness.\n";
            }
            else {
                s.insert(u);
                mp[u] = 0;
                Q.push_back(u);
                cout << op << Cnt++ << ": success.\n";
            }
        }
        else if (str == "Close") {
            cin >> u;
            if (s.count(u)) {
                s.erase(u);
                if (topWin == u) topWin = INT32_MAX;
                for (auto j = Q.begin(); j != Q.end(); j++) {
                    if (*j == u) {
                        Q.erase(j);
                        break;
                    }
                }
                cout << op << Cnt++ << ": close " << u << " with " << mp[u] << ".\n";
            }
            else {
                cout << op << Cnt++ << ": invalid likeness.\n";
            }
        }
        else if (str == "Chat") {
            cin >> u;
            if (s.size() > 0) {
                if (topWin != INT32_MAX)
                    mp[topWin] += u;
                else {
                    int f = Q.front();
                    mp[f] += u;
                }
                cout << op << Cnt++ << ": success.\n";
            }
            else {
                cout << op << Cnt++ << ": empty.\n";
            }
        }
        else if (str == "Rotate") {
            cin >> u;

            if (u >= 1 && u <= s.size()) {
                int r = 0, tmp;
                for (auto j = Q.begin(); j != Q.end(); j++) {
                    ++r;
                    if (r == u) {
                        tmp = *j;
                        Q.erase(j);
                        Q.push_front(tmp);
                        break;
                    }
                }    
                cout << op << Cnt++ << ": success.\n";            
            }
            else {
                cout << op << Cnt++ << ": out of range.\n";
            }

        }
        else if (str == "Prior") {
            if (s.size() > 0) {
                int Max = INT32_MIN;
                auto tmp = Q.begin();
                for (auto j = Q.begin(); j != Q.end(); j++) {
                    if (*j > Max) {
                        Max = *j;
                        tmp = j;
                    }
                }
                Q.erase(tmp);
                Q.push_front(Max);     
                cout << op << Cnt++ << ": success.\n";
            }
            else {
                cout << op << Cnt++ << ": empty.\n";
            }

        }
        else if (str == "Choose") {
            cin >> u;
            if (s.count(u)) {
                for (auto j = Q.begin(); j != Q.end(); j++) {
                    if (*j == u) {
                        Q.erase(j);
                        break;
                    }
                }
                Q.push_front(u);
                cout << op << Cnt++ << ": success.\n";                
            }
            else {
                cout << op << Cnt++ << ": invalid likeness.\n";
            }
        }
        else if (str == "Top") {
            cin >> u;
            if (s.count(u)) {
                topWin = u;
                cout << op << Cnt++ << ": success.\n";
            }
            else {
                cout << op << Cnt++ << ": invalid likeness.\n";
            }
        }
        else if (str == "Untop") {
            if (topWin == INT32_MAX) {
                cout << op << Cnt++ << ": no such person.\n";
            }
            else {
                topWin = INT32_MAX;
                cout << op << Cnt++ << ": success.\n";
            }
        }

    }

    if (topWin != INT32_MAX) {
        if (mp[topWin] > 0)
            cout << op << Cnt++ << ": Bye " << topWin << ": " << mp[topWin] << ".\n";
    }

    while (!Q.empty()) {
        int f = Q.front();
        Q.pop_front();
        if (f == topWin) continue;
        if (mp[f] > 0) cout << op << Cnt++ << ": Bye " << f << ": " << mp[f] << ".\n";
    }
}

int main() {

    // freopen("out", "w", stdout);

    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    

    int t;
    cin >> t;
    while (t--) {
        Cnt = 1;
        topWin = INT32_MAX;
        s.clear();
        mp.clear();
        solve();
    }
    return 0;
}
