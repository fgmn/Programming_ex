#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

vector<pair<int, int> > a(2005);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a[i] = {x, y};
    } 

    int ans = 0, j = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (a[j].first >= y) {
            continue;
        } 
        
        TAG: while (j < n && a[j].second <= x) {
            j++;
        }

        if (j < n) ans += max(min(a[j].second, y) - max(a[j].first, x), 0);

        if (j < n && y > a[j].second) {
            j++;
            goto TAG;
        }

        // cout << "(x, y): " << x << ' ' << y << '\n';
        // cout << "(fi, se):" << a[j].first << ' ' << a[j].second << '\n';
    }
    cout << ans;
    return 0;
}
