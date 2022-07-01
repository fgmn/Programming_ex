#include<bits/stdc++.h>
#define D 0
using namespace std;
using ll = long long;

const int N = 5e3 + 10;

// 换行符视作普通字符
// 粘滞功能 -> 选中状态

pair<int, int> cursor, spot;  // 光标移动
int sz[N];  // 维护每行字符串长度
int row;    // 当前有效行数
// 记事本
string notepad;
// 剪贴板
string clipboard;
// 粘滞功能
bool v;
// 选中状态
bool selected;

int moveCursor(int op) {
    if (op == 1) {
        cursor.second = 0;
    }
    else if (op == 2) {
        cursor.second = sz[cursor.first];
    }
    else if (op == 3) {
        if (cursor.first > 1) cursor.first--;
        if (cursor.second > sz[cursor.first])
            cursor.second = sz[cursor.first];
    }
    else if (op == 4) {
        if (cursor.first < row) cursor.first++;
        if (cursor.second > sz[cursor.first])
            cursor.second = sz[cursor.first];        
    }
    else if (op == 5) {
        if (cursor.first == 1 && cursor.second == 0) return 0;
        cursor.second--;
        if (cursor.second < 0) {
            cursor.first--;
            cursor.second = sz[cursor.first];
        }
    }
    else if (op == 6) {
        if (cursor.first == row && cursor.second == sz[row]) return 0;
        cursor.second++;
        if (cursor.second > sz[cursor.first]) {
            cursor.first++;
            cursor.second = 0;
        }
    }
    return 1;
}

// 获取光标位置
int getPos() {
    int pos = 0;
    for (int i = 1; i < cursor.first; i++) {
        pos += (sz[i] + 1);
    }
    pos += cursor.second;
    return pos;
}

int getPos(pair<int, int> p) {
    int pos = 0;
    for (int i = 1; i < p.first; i++) {
        pos += (sz[i] + 1);
    }
    pos += p.second;
    return pos;
}

int getWord(string c) {
    int cnt = 0;
    int l = c.length();
    for (int i = 0; i < l; i++) {
        if (c[i] != '\n') cnt++;
    }
    return cnt;
}

// 插入单元字符
void input(string c) {
    int pos = getPos();

    string a = notepad.substr(0, pos);
    string b = notepad.substr(pos);

    notepad = a + c + b;

    // 增加行
    if (c == "\n") {
        row++;
        for (int i = row; i > cursor.first + 1; i--) {
            sz[i] = sz[i - 1];
        }
        sz[cursor.first + 1] = sz[cursor.first] - cursor.second;
        sz[cursor.first] = cursor.second;
        
        cursor.first++;
        cursor.second = 0;
    }
    else {
        int inc = c.length();
        cursor.second += inc;
        sz[cursor.first] += inc;
    }
}

// 删除当前光标位置之后的一个字符
void delet() {
    if (cursor.first == row && cursor.second == sz[row]) return;
    int pos = getPos();

    string a = notepad.substr(0, pos);
    string b = notepad.substr(pos + 1);
    string c = notepad.substr(pos, 1);

    notepad = a + b;

    // 合并行
    if (c == "\n") {
        sz[cursor.first] += sz[cursor.first + 1];
        for (int i = cursor.first + 1; i < row; i++) {
            sz[i] = sz[i + 1];
        }
        sz[row] = 0;
        row--;
    }
    else {
        sz[cursor.first]--;
    }
}

void removeSelected() {
    if (spot > cursor) swap(spot, cursor);

    while (cursor != spot) {
        moveCursor(5);
        delet();
    }
}

// O(n)
void find(string word) {
    int l = notepad.length(), cnt = 0, i = 0;

    if (selected) {
        int a = getPos(spot);
        int b = getPos();
        if (b < a) swap(a, b);

        string target = notepad.substr(a, b - a);

        while ((i = target.find(word, i)) != -1) {
            i++;
            cnt++;
        }
        cout << cnt << '\n';
        return;
    }

    while ((i = notepad.find(word, i)) != -1) {
        i++;
        cnt++;
    }
    cout << cnt << '\n';
}

// 统计可见字符 O(n)
void count() {
    int cnt = 0;

    if (selected) {
        int a = getPos(spot);
        int b = getPos();
        if (b < a) swap(a, b);

        for (int i = a; i < b; i++) {
            if (notepad[i] != ' ' && notepad[i] != '\n') cnt++;
        }
        cout << cnt << '\n';
        return;
    }

    int l = notepad.length();
    for (int i = 0; i < l; i++) {
        if (notepad[i] != ' ' && notepad[i] != '\n') cnt++;
    }
    cout << cnt << '\n';
}

void copy() {
    if (selected) {
        int a = getPos(spot);
        int b = getPos();
        if (b < a) swap(a, b);
        clipboard = notepad.substr(a, b - a);
    }
    else if (sz[cursor.first]) {    // 不为空
        // 复制当前行的内容
        int pos = getPos() - cursor.second;
        clipboard = notepad.substr(pos, sz[cursor.first]);
    }
}

void print() {
    cout << notepad;
    cout << '\n';
}

void work() {
    int n;
    cin >> n;

    string cmd, type, c;
    for (int i = 1; i <= n; i++) {
        cin >> cmd;
        if (D) cout << cmd << '\n';
        if (cmd == "MOVE") {
            if (selected) {
                selected = false;
            }
            cin >> type;
            if (type == "Home") moveCursor(1);
            else if (type == "End") moveCursor(2);
            else if (type == "Up") moveCursor(3);
            else if (type == "Down") moveCursor(4);
            else if (type == "Left") moveCursor(5);
            else if (type == "Right") moveCursor(6);
        }
        else if (cmd == "INSERT") {
            if (selected) {
                // 删除选中部分，可能包含多行
                // 逐个删除即可
                removeSelected();
                selected = false;
            }
            cin >> type;
            if (type == "Char") {
                cin >> c;
                input(c);
            }
            else if (type == "Enter") input("\n");
            else if (type == "Space") input(" ");
            else if (type == "Paste") {
                // 逐个字符插入
                if (clipboard != "") {
                    int sl = clipboard.length();
                    for (int i = 0; i < sl; i++) {
                        input(clipboard.substr(i, 1));      // string -> char
                    }
                }    
            }
        }
        else if (cmd == "REMOVE") {
            cin >> type;
            if (selected) {
                // 同INSERT
                removeSelected();
                selected = false;
                continue;
            }
            if (type == "Del") {
                delet();
            }
            else {
                int res = moveCursor(5);
                if (res) delet();
            }
        }
        else if (cmd == "SHIFT") {
            if (selected) {
                selected = false;
                v = true;
                continue;
                // 保留上一次选中字段的记录点作为当前记录点
            }
            // 记录点
            if (!v) spot = cursor, v = true;
            else {
                v = false;
                if (spot != cursor) selected = true;
            }
        }
        else if (cmd == "FIND") {
            cin >> c;
            find(c);
        }
        else if (cmd == "COUNT") {
            count();
        }
        else if (cmd == "COPY") {
            copy();
        }
        else if (cmd == "PRINT") {
            print();
        }
        if (D) print();
    }
}

void init() {
    row = 1;
    cursor.first = 1;
    clipboard = "";
    selected = false;
    v = false;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // freopen("25.in", "r", stdin);
    // freopen("c.out", "w", stdout);

    init();

    work();

    return 0;
}

/*
15
INSERT Char 1
INSERT Char 2
INSERT Char 3
INSERT Enter
INSERT Char 1
INSERT Char 2
SHIFT
MOVE Left
MOVE Left
MOVE Left
SHIFT
COPY
MOVE Right
INSERT Paste
PRINT
*/