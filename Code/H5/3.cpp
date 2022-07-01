#include<bits/stdc++.h>
using namespace std;
using ll = long long;

deque<int> Q;
int a[1000010];
int n, k;

void find(int opt) {
    Q.clear();
    for (int i = 0; i < n; i++) {
        while (!Q.empty() && Q.front() < i - k + 1) Q.pop_front();
        while (!Q.empty() && a[Q.back()] >= a[i]) Q.pop_back();
        Q.push_back(i);
        if (i >= k - 1) cout << opt * a[Q.front()] << " ";
    }
    cout << '\n';
}

void solve() {
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> a[i];
    find(1);
    for (int i = 0; i < n; i++) a[i] = -a[i];
    find(-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
