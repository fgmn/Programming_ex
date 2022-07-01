#include<bits/stdc++.h>
using namespace std;
using ll = long long;

set<int> SetX[10005], SetY[10005];
bool Reach[10005][10005];

void solve() {
    int n, m, k;
    cin >> n >> m;
    cin >> k;

    int x, y, ans = 0;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        SetX[x].insert(y);
        SetY[y].insert(x);
    }

    int t;
    cin >> t;

    int cX = 1, cY = 1;
    if (SetX[1].count(1)) {
        ans++;
        SetX[1].erase(1);
        SetY[1].erase(1);
    }

    char Dir;
    int step, D;

    while (t--) {
        cin >> Dir >> step;

        // (cX, cY) -> (cX + Step[D][0] * step, cY + Step[D][1] * step)
        int nX = cX, nY = cY;
        set<int>::iterator A, B, Clr;

        if (Dir == 'W') {
            nX -= step;
            A = SetY[cY].lower_bound(nX);
            B = SetY[cY].lower_bound(cX);

            if (A == SetY[cY].end() || B == SetY[cY].begin())
                goto TAG;
            B--;
            if (*A > *B) goto TAG;
            while (A != B) {
                if (!Reach[*A][cY]) {
                   Reach[*A][cY] = 1;
                   ans++;
                }
                Clr = A;
                A++;
                SetY[cY].erase(Clr);
                
            }
            if (!Reach[*A][cY]) {
                Reach[*A][cY] = 1;
                ans++;
            }
        }
        else if (Dir == 'A') {
            nY -= step;
            A = SetX[cX].lower_bound(nY);
            B = SetX[cX].lower_bound(cY);
           
            if (A == SetX[cX].end() || B == SetX[cX].begin())
                goto TAG;
            B--;
            if (*A > *B) goto TAG;
            while (A != B) {
                if (!Reach[cX][*A]) {
                   Reach[cX][*A] = 1;
                   ans++;
                }
                Clr = A;
                A++;
                SetX[cX].erase(Clr);
            }
            if (!Reach[cX][*A]) {
                Reach[cX][*A] = 1;
                ans++;
            }
        }
        else if (Dir == 'S') {
            nX += step;
            A = SetY[cY].upper_bound(cX);
            B = SetY[cY].upper_bound(nX);
            
            if (A == SetY[cY].end() || B == SetY[cY].begin())
                goto TAG;
            B--;
            if (*A > *B) goto TAG;
            while (A != B) {
                if (!Reach[*A][cY]) {
                   Reach[*A][cY] = 1;
                   ans++;
                }
                Clr = A;
                A++;
                SetY[cY].erase(Clr);
            }
            if (!Reach[*A][cY]) {
                Reach[*A][cY] = 1;
                ans++;
            }
        }
        else if (Dir == 'D') {
            nY += step;
            A = SetX[cX].upper_bound(cY);
            B = SetX[cX].upper_bound(nY);
            
            if (A == SetX[cX].end() || B == SetX[cX].begin())
                goto TAG;
            B--;
            if (*A > *B) goto TAG;
            while (A != B) {
                if (!Reach[cX][*A]) {
                   Reach[cX][*A] = 1;
                   ans++;
                }
                Clr = A;
                A++;
                SetX[cX].erase(Clr);
            }
            if (!Reach[cX][*A]) {
                Reach[cX][*A] = 1;
                ans++;
            }
        } 
        TAG: cX = nX, cY = nY;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    solve();
    return 0;
}
