#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    set<string> S;
    while (m--) {
        int op;
        string str;
        cin >> op;

        if (op == 1) {
            cin >> str;
            if (S.find(str) != S.end()) {
                cout << "found\n";
            }
            else {
                cout << "write\n";
                S.insert(str);
            }
        }
        else if (op == 2) {
            cin >> str;
            if (S.find(str) != S.end()) {
                cout << "erased\n";
                S.erase(str);
            }
            else {
                cout << "not found\n";
            }
        }
        else {
            for (auto i : S) {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
