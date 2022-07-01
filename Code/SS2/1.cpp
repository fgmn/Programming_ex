#include<bits/stdc++.h>
#define CO 60
using namespace std;
using ll = long long;

// 矩阵大小与选择的时间差绝对值

// 判断某个时刻是否能拼成正方形
int J(int a, int b, int c, int d, int e, int f) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    if (e > f) swap(e, f);

    if ((!a) || (!c) || (!e)) return -1;

    if (b == d && d == f) {
        if (a + c + e == b) return b;
    }

    if (b > d) {
        swap(a, c);
        swap(b, d);
    }
    if (d > f) {
        swap(c, e);
        swap(d, f);
    }

    if (a == c) {
        if (b + d == f && a + e == f) return f;
    }
    if (a == d) {
        if (b + c == f && a + e == f) return f;
    }
    if (b == c) {
        if (a + d == f && b + e == f) return f;
    }
    if (b == d) {
        if (a + c == f && b + e == f) return f;
    }

    return -1;
}

struct T
{
    int x, y, z;

    bool operator < (const T &a) {
        if (x != a.x) return x < a.x;
        if (y != a.y) return y < a.y;
        return z < a.z;
    }
};

T N(T a) {
    a.z++;
    if (a.z >= 60) {
        a.z = 0;
        a.y++;
    }
    if (a.y >= 60) {
        a.y = 0;
        a.x++;
    }
    if (a.x >= 24) {
        a.x = 0;
    }
    return a;
}

int cal(T a, T b) {
    ll A = ((a.x * CO) + a.y) * CO + a.z;    // 86400
    ll B = ((b.x * CO) + b.y) * CO + b.z;

    return B - A;
}

void OUT(T a) {
    if (a.x < 10) {
        cout << 0;
    }
    cout << a.x << ":";
    if (a.y < 10) {
        cout << 0;
    }
    cout << a.y << ":";
    if (a.z < 10) {
        cout << 0;
    }
    cout << a.z;
}

void A(int a, int b, int c, int d, int e, int f) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    if (e > f) swap(e, f);


    if (b == d && d == f) {
        if (a + c + e == b) {
            for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) {
                    cout << 0;
                }
                cout << '\n';
            }
            for (int i = 1; i <= c; i++) {
                for (int j = 1; j <= b; j++) {
                    cout << 1;
                }
                cout << '\n';
            }               
            for (int i = 1; i <= e; i++) {
                for (int j = 1; j <= b; j++) {
                    cout << 2;
                }
                cout << '\n';
            }    
            return;       
        }
    }

    if (b > d) {
        swap(a, c);
        swap(b, d);
    }
    if (d > f) {
        swap(c, e);
        swap(d, f);
    }

    for (int i = 1; i <= e; i++) {
        for (int j = 1; j <= f; j++) {
            cout << 0;
        }
        cout << '\n';
    }

    if (a == c) {
        if (b + d == f && a + e == f) {
            for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) cout << 1;
                for (int j = 1; j <= d; j++) cout << 2;
                cout << '\n';
            }
            return;
        }
    }
    if (a == d) {
        if (b + c == f && a + e == f) {
            for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) cout << 1;
                for (int j = 1; j <= c; j++) cout << 2;
                cout << '\n';
            } 
            return;
        }
    }
    if (b == c) {
        if (a + d == f && b + e == f) {
            for (int i = 1; i <= b; i++) {
                for (int j = 1; j <= a; j++) cout << 1;
                for (int j = 1; j <= d; j++) cout << 2;
                cout << '\n';
            }
            return;
        }
    }
    if (b == d) {
        if (a + c == f && b + e == f) {
            for (int i = 1; i <= b; i++) {
                for (int j = 1; j <= a; j++) cout << 1;
                for (int j = 1; j <= c; j++) cout << 2;
                cout << '\n';
            }
            return;
        }
    }
    
}

void solve() {
    T t1, t2;
    cin >> t1.x >> t1.y >> t1.z >> t2.x >> t2.y >> t2.z;
    t2 = N(t2);

    T ans1, ans2;
    int c = INT32_MAX;
    int L, D;
    for (T i = t1; i < t2; i = N(i)) {
        for (T j = i; j < t2; j = N(j)) {

            int ret = J(i.x, i.y, i.z, j.x, j.y, j.z);
            if (ret == -1) continue;
            int delt = cal(i, j);
            
            // cout << "ret = " << ret << '\n';
            // cout << "delt = " << delt << '\n';
            // OUT(i);
            // cout << ' ';
            // OUT(j);
            // cout << '\n';
            if (c > abs(ret * ret - delt)) {
                L = ret;
                D = delt;
                c = abs(ret * ret - delt);
                ans1 = i;
                ans2 = j;
            }

            if (c == abs(ret * ret - delt) && D > delt) {
                L = ret;
                D = delt;
                ans1 = i;
                ans2 = j;
            }
        }
    }

    if (c == INT32_MAX) {
        cout << "-1\n";
    }
    else {
        cout << L << '\n';
        OUT(ans1);
        cout << ' ';
        OUT(ans2);
        cout << '\n';
        cout << cal(ans1, ans2) << ' ' << c << '\n';
        A(ans1.x, ans1.y, ans1.z, ans2.x, ans2.y, ans2.z);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ":\n";
        solve();
        cout << '\n';
    }
    return 0;
}
