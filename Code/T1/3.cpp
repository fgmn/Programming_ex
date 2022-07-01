#include<bits/stdc++.h>
using namespace std;
using ll = long long;

char Cut[305];
ll mX, mY, mZ;
// 维护三个方向上最大长度
vector<int> X, Y, Z;

void solve() {
    int n, m;
    cin >> n >> m;
    mX = mY = mZ = n;

    for (int i = 1; i <= m; i++) {
        cin >> Cut[i];
    }
    
    X.push_back(0);
    X.push_back(n);
    Y.push_back(0);
    Y.push_back(n);
    Z.push_back(0);
    Z.push_back(n);

    int a, Max;
    for (int i = 1; i <= m; i++) {
        Max = 0;
        cin >> a;
        if (Cut[i] == 'x') {
            X.push_back(a);
            sort(X.begin(), X.end());
            for (int j = 1; j < X.size(); j++) {
                if (X[j] - X[j - 1] > Max) Max = X[j] - X[j - 1];
            }
            mX = Max;
        }
        else if (Cut[i] == 'y') {
            Y.push_back(a);
            sort(Y.begin(), Y.end());
            for (int j = 1; j < Y.size(); j++) {
                if (Y[j] - Y[j - 1] > Max) Max = Y[j] - Y[j - 1];
            }
            mY = Max;
        }
        else {
            Z.push_back(a);
            sort(Z.begin(), Z.end());
            for (int j = 1; j < Z.size(); j++) {
                if (Z[j] - Z[j - 1] > Max) Max = Z[j] - Z[j - 1];
            }
            mZ = Max;
        }
        // cout << mX << " " << mY << " " << mZ << '\n';
        cout << 1ll * mX * mY * mZ << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
