#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > a;
    int x, y;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a.push_back({y, x});
    }

    sort(a.begin(), a.end());
    auto it = a.begin();

    for (int i = 1; i <= n;) {
        if (it != a.end() && it->first == i) {
            cout << it->second << " ";
            it++;
        }
        else {
            i++;
            cout << '\n';
        }
    }
    return 0;
}
