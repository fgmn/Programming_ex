#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
using ll = long long;

// 6 0 1 2 3 4 5

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    int Max = INT32_MIN, Min = INT32_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
    }
    sort(a.begin(), a.end());

    double mid;
    bool flag = true;
    
    if (n % 2 == 0) {
        mid = 1.0 * (a[n / 2] + a[n / 2 - 1]) / 2;
        if ((a[n / 2] + a[n / 2 - 1]) % 2) flag = false;
    }

    cout << Max << ' ';
    if (n % 2) cout << a[n / 2] << ' ';
    else {
        if (flag) cout << (a[n / 2] + a[n / 2 - 1]) / 2 << ' ';
        else cout << setiosflags(ios::fixed) << setprecision(1) << mid << ' ';        
    }
    cout << Min << '\n';

    return 0;
}