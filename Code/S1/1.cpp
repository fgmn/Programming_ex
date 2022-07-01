#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int A, B;
int a1, b1, a2, b2;
int Cnt[10];
int Sort[5];      // 排序大小

struct card {
    int x, y;

    // bool operator == (card &ano) const {
    //     return (x == ano.x && y == ano.y);
    // }
}C[6];

bool f2 () {
    // 炸弹
    int tmp = 0, res = 0;
    for (int i = 2; i <= 5; i++) {
        if (C[1].x == C[i].x) tmp++;
    }
    res = max(res, tmp);
    tmp = 0;
    for (int i = 4; i >= 1; i--) {
        if (C[5].x == C[i].x) tmp++;
    }
    res = max(res, tmp);

    if (res >= 3) return true;
    return false;
}

bool f3() {
    // 三带二
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (Sort[i] == Sort[i + 1]) res++;
    }

    if (res == 3) return true;
    return false;
}

bool f4() {
    int res = 0;
    for (int i = 4; i >= 1; i--) {
        if (C[5].y == C[i].y) res++;
    }

    if (res == 4) return true;
    return false;
}

bool f5() {
    // 顺子
    int tmp[5], ok = true;

    for (int i = 0; i < 5; i++) {
        tmp[i] = C[i + 1].x;
    }

    sort(tmp, tmp + 5);

    for (int i = 0; i < 4 ; i++) {
        if (tmp[i] + 1 != tmp[i + 1]) {
            ok = false;
            break;
        }
    }

    return ok;
}

bool f1 () {
    // 同花顺
    if (f4() && f5()) return true;
    return false;
}

bool f6() {
    bool ok = false;

    for (int i = 0; i < 4; i++) {
        if (Sort[i] == Sort[i + 1]) {
            if (ok == true) return true;
            ok = true;
        }
        else {
            ok = false;
        }
    }

    return false;
}

bool f7() {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (Sort[i] == Sort[i + 1]) 
            res++;
    }

    if (res == 2) return true;
    return false;
}

bool f8() {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (Sort[i] == Sort[i + 1]) 
            return true;
    }

    return false;
}

void count(int a, int b, int c) {
    C[3].x = a / B;
    C[3].y = a % B;
    C[4].x = b / B;
    C[4].y = b % B;
    C[5].x = c / B;
    C[5].y = c % B;

    for (int i = 0; i < 5; i++) {
        Sort[i] = C[i + 1].x;
    }

    sort(Sort, Sort + 5);

    if (f1()) Cnt[1]++;
    else if (f2()) Cnt[2]++;
    else if (f3()) Cnt[3]++;
    else if (f4()) Cnt[4]++;
    else if (f5()) Cnt[5]++;
    else if (f6()) Cnt[6]++;
    else if (f7()) Cnt[7]++;
    else if (f8()) Cnt[8]++;
    else Cnt[9]++;
}

void solve() {
    cin >> A >> B;
    cin >> a1 >> b1 >> a2 >> b2;

    C[1].x = a1;
    C[1].y = b1;
    C[2].x = a2;
    C[2].y = b2;   

    // C_98^3
    for (int i = 0; i < A * B; i++) {       // % B
        if (a1 * B + b1 == i || a2 * B + b2 == i)
            continue;
        for (int j = i + 1; j < A * B; j++) {
            if (a1 * B + b1 == j || a2 * B + b2 == j)
                continue;   
            for (int k = j + 1; k < A * B; k++) {
                if (a1 * B + b1 == k || a2 * B + b2 == k)
                    continue;  
                count(i, j, k);
            }
        }
    }


    for (int i = 1; i <= 9; i++) {
        cout << Cnt[i] << " ";
    }
    cout << '\n';
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
