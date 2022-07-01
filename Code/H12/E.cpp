#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

// 2^40
vector<pair<ll, ll> > s1, s2;

vector<pair<ll, ll> > cal(vector<pair<ll, ll> > k) {
    vector<pair<ll, ll> > res;

    int sz = k.size();
    if (sz < 1) return res;
    for (int i = 0; i < (1 << sz); i++) {
        ll W = 0, C = 0;
        for (int j = 0; j < sz; j++) {
            if ((i >> j) & 1) {
                W += k[j].first;
                C += k[j].second;
            }
        }
        res.push_back({W, C});
    }
    return res;
}

bool cmp(pair<ll, ll> p, pair<ll, ll> q) {
    if (p.first != q.second)
        return p.first < q.first;
    return p.second > q.second;
}

/*
1 3
1 2
2 3
2 1
*/ 

vector<pair<ll, ll> > cl(vector<pair<ll, ll> > k) {
    vector<pair<ll, ll> > res;
    int sz = k.size();
    if (sz < 1) return res;
    res.push_back({k[0].first, k[0].second});
    for (int i = 1; i < sz; i++) {
        ll C = res.back().second;
        if (k[i].second > C) {
            res.push_back({k[i].first, k[i].second});
        }
    }
    return res;
}

void solve() {
    int n, v;
    cin >> n >> v;

    ll w, c;
    for (int i = 1; i <= min(n, 20); i++) {
        cin >> w >> c;
        s1.push_back({w, c});
    }
    for (int i = 1; i <= n - 20; i++) {
        cin >> w >> c;
        s2.push_back({w, c});        
    }

    s1 = cal(s1);
    s2 = cal(s2);

    sort(s1.begin(), s1.end(), cmp);
    sort(s2.begin(), s2.end(), cmp);

    s1 = cl(s1);
    s2 = cl(s2);

    ll ans = 0;
    if (n <= 20) {
        for (int i = 0; i < s1.size(); i++) {
            if (v >= s1[i].first) ans = max(ans, s1[i].second);
        }
        cout << ans << '\n';
        return;
    }

    int sz = s1.size();
    for (int i = 0; i < sz; i++) {
        if (s1[i].first > v) break;
        int pos = -1;
        int l = 0, r = s2.size();
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (s2[mid].first + s1[i].first <= v) {
                pos = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        if (pos == -1) {
            ans = max(ans, s1[i].second);
        }
        else {
            ans = max(ans, s1[i].second + s2[pos].second);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
