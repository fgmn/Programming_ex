#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// hh:MM:ss -> hh * 3600 + MM * 60 + ss
const int N = 305;
int n, m;
map<string, string> m1;
map<string, int> m2;        // <学号， 编号>
map<int, string> m3;

int t1, t2, tClass;
int T[N];   // 有效时间
bool ok[N]; // 签到

int strtoTime(string s) {
    int hh = ((s[0] - '0') * 10 + (s[1] - '0'));
    int MM = ((s[3] - '0') * 10 + (s[4] - '0'));
    int ss = ((s[6] - '0') * 10 + (s[7] - '0'));

    return hh * 3600 + MM * 60 + ss;
}

// (t1, t2)
int calValTime(int a1, int a2) {
    if (a1 >= t2 || t1 >= a2) return 0;
    return min(a2, t2) - max(a1, t1);
}

void solve() {
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;

    t1 = strtoTime(s1);
    t2 = strtoTime(s2);
    tClass = t2 - t1;

    for (int i = 1; i <= n; i++) {
        cin >> s1 >> s2;
        m2[s1] = i;
        m3[i] = s1;
        m1[s2] = s1;
    }

    string id, OK, stuNum;
    int No;
    for (int i = 1; i <= m; i++) {
        cin >> id >> s1 >> s2 >> OK;

        int L = id.length();
        if (isdigit(id[L - 1])) {
            stuNum = id.substr(L - 12, 12);
        }
        else stuNum = m1[id];
        No = m2[stuNum];

        int valTime = calValTime(strtoTime(s1), strtoTime(s2));
        T[No] += valTime;
        if (OK == "Yes") ok[No] = true;
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << T[i] << " ";
    // }
    // cout << '\n';

    int Cnt = n;
    for (int i = 1; i <= n; i++) {
        if (!T[i]) {
            cout << m3[i] << " A\n";
        }
        else if (T[i] * 2 <= tClass) {
            cout << m3[i] << " L\n";
        }
        else if (!ok[i]) {
            cout << m3[i] << " D\n";
        }
        else Cnt--;
    }
    if (!Cnt) cout << "Well done.\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, cas = 1;
    cin >> t;
    while (t--) {
        cout << "Case #" << cas++ << ":\n";

        memset(T, 0, sizeof T);
        memset(ok, false, sizeof ok);
        m1.clear();
        m2.clear();
        m3.clear();

        solve();
    }
    return 0;
}
