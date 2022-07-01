#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    cin >> n;
    vector<int> a(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> b;
        cout << ++a[b] << ' ';
    }
    cout << '\n';
    
    return 0;
}
