#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << (a[0] + a[1]) / 2 << ' ';
    for (int i = 1; i < n - 1; i++) {
        cout << (a[i - 1] + a[i] + a[i + 1]) / 3 << ' ';
    }
    cout << (a[n - 2] + a[n - 1]) / 2 << ' ';
    return 0;
}
