#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + 1 == a[i + 1]) ans++;
    }
    cout << ans << '\n';
    
    return 0;
}
