#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;

const int N = 1e6 + 5;

vector<int> g[N];
int d[N];
int n, m;

void toposort() {
    priority_queue<int, vector<int>, greater<int> > q;

    for (int i = 1; i <= n; i++) {
        if (!d[i]) q.push(i);
    }

    while (!q.empty()) {
        int u = q.top();
        q.pop();
        cout << u << ' ';

        for (int v : g[u]) {
            if (--d[v] == 0) {
                q.push(v);
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int a, b;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        d[b]++;
    }
    toposort();
    return 0;
}
