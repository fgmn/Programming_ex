#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
using namespace std;
using ll = long long;

// 原子操作：读取一个整数
ll readInt(string &s, ll &p) {
    ll res = 0;
    bool flag = false;

    while (p != s.size() && isdigit(s[p])) {
        flag = true;
        res = res * 10 + (s[p] - '0');
        p++;
    }

    if (flag) return res;
    return 1;
}

// 根据符号对字符串进行分隔
vector<string> split(string &s, char c) {
    stringstream ss(s);
    vector<string> res;
    string t;

    while (getline(ss, t, c)) {
        res.push_back(t);
    }
    return res;
}

// 合并两个答案字典
void merge(map<string, ll> &res, map<string, ll> const & a, ll coef) {
    for (auto &i : a) {
        res[i.first] += i.second * coef;
    }
}

map<string, ll> readItem(string &s, ll &p);

// 读取化学式
map<string, ll> readFormula(string &s, ll &p) {
    map<string, ll> res, a;

    while (s[p] != ')') {
        a = readItem(s, p);
        // ll c = readInt(s, p);
        merge(res, a, 1);   // 逐项合并至答案
    }

    return res;
}

// 读取元素
string readElement(string &s, ll &p) {
    string res;
    res = s[p++];   // 读取首个字母
    while (p != s.size() && islower(s[p])) {    // 若是小写字母则和前面字母构成一个元素
        res += s[p];
        p++;
    }
    return res;
}

// 读取一项
map<string, ll> readItem(string &s, ll &p) {
    map<string, ll> res, a;

    if (s[p] == '(') {
        p++;
        a = readFormula(s, p);
        p++;    // ')'
        ll c = readInt(s, p);   // 像Ca(OH)2,要读取括号后参数乘至答案
        merge(res, a, c);
    }
    else {
        string b = readElement(s, p);   // 读一项:读一个元素，读一个系数
        ll c = readInt(s, p);
        res[b] += c;
    }

    return res;
}

map<string, ll> J(string s) {   // 求表达式的元素统计表
    vector<string> f = split(s, '+');
    map<string, ll> res, a;

    for (int i = 0; i < f.size(); i++) {
        a.clear();
        ll p = 0;
        ll coef = readInt(f[i], p);     // 读整体系数，像4H2O中的‘4’
        while (p != f[i].size()) {      // 逐项读取化学式，直至化学式结束
            a = readItem(f[i], p);      
            merge(res, a, coef);            
        }
    }
    return res;
}

void solve() {
    int n; cin >> n;

    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        vector<string> res = split(s, '=');     // 以‘=’分隔得到左右表达式

        if (J(res[0]) == J(res[1])) {
            cout << "Y\n";
        }
        else cout << "N\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
