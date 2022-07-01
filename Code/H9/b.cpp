#include<iostream>
#include<map>
#include<vector>
#include<sstream>
using namespace std;
using ll = long long;

struct file
{
    bool D;         // 是否是目录文件
    ll ld, lr;      // 目录配额 后代配额
    ll sd, sr;      // 实际孩子文件大小 实际后代文件大小
    map<string, file> children;

    ll fileSize;

    file() {
        D = true;
        ld = lr = 1e18;
        sd = sr = 0;
        fileSize = 0;
    }
};

// 解析文件路径： /a/b/c/1 -> {"", "a", "b", "c", "1"}
vector<string> parsePath(string &path) {
    stringstream ss(path);
    string fileName;
    vector<string> res;

    while (getline(ss, fileName, '/')) {
        res.push_back(fileName);
    }
    return res;
}

// 根目录文件
file root;

// 查找文件，返回文件指针集合，代表目录树和查找文件的最大重合路径，支持对目录树的修改
vector<file *> findPath(vector<string> &fileNames) {
    vector<file *> res;
    res.push_back(&root);
    
    for (int i = 1; i < fileNames.size(); i++) {
        // 普通文件没有后代
        if (res.back()->D == false) {
            break;
        }
        // 后代中没有重合路径
        if (res.back()->children.count(fileNames[i]) == 0) {
            break;
        }
        res.push_back(&res.back()->children[fileNames[i]]);
    }
    return res;
}

bool create() {
    string path;
    ll fileSize;
    cin >> path >> fileSize;

    auto fileNames = parsePath(path);
    auto filePtrs = findPath(fileNames);
    ll inc;
    // 若最大重合路径和查找文件的路径长度相同，代表找到文件
    if (fileNames.size() == filePtrs.size()) {
        // 目录文件不支持修改
        if (filePtrs.back()->D) {
            return false;
        }
        else {
            // inc = 和原来文件大小的差量
            inc = fileSize - filePtrs.back()->fileSize;
        }
    }
    else {
        if (filePtrs.back()->D == false) {
            return false;
        }   // 与孩子文件重名
        else inc = fileSize;
    }

    // 检查配额
    for (int i = 0; i < filePtrs.size(); i++) {
        if (filePtrs[i]->sr + inc > filePtrs[i]->lr) {
            return false;
        }
        // 双亲目录同时检查目录配额
        if (i == fileNames.size() - 2) {
            if (filePtrs[i]->sd + inc > filePtrs[i]->ld) {
                return false;
            }
        }
    }

    // 创建文件
    for (int i = filePtrs.size(); i < fileNames.size(); i++) {
        filePtrs.push_back(&filePtrs.back()->children[fileNames[i]]);
    }

    filePtrs.back()->D = false;
    filePtrs.back()->fileSize = fileSize;

    // 更新实际文件大小
    for (auto &i : filePtrs) {
        i->sr += inc;
    }
    filePtrs.end()[-2]->sd += inc; 
    return true;
}

bool remove() {
    string path;
    cin >> path;

    auto fileNames = parsePath(path);
    auto filePtrs = findPath(fileNames);
    // 没有找到文件则不用移除，直接返回成功
    if (fileNames.size() != filePtrs.size()) {
        return true;
    } 
    // 移除目录文件
    if (filePtrs.back()->D) {
        for (auto &i : filePtrs) {
            i->sr -= filePtrs.back()->sr;
        }
    }
    else {      // 移除普通文件
        for (auto &i : filePtrs) {
            i->sr -= filePtrs.back()->fileSize;
        }
        filePtrs.end()[-2]->sd -= filePtrs.back()->fileSize;
    }
    filePtrs.end()[-2]->children.erase(fileNames.back());
    return true;
}

bool modify() {
    string path;
    ll d, r;
    cin >> path >> d >> r;

    auto fileNames = parsePath(path);
    auto filePtrs = findPath(fileNames);

    if (fileNames.size() != filePtrs.size()) {
        return false;
    }
    if (filePtrs.back()->D == false) {
        return false;
    }

    // 0代表不限额，设置为1e18
    if (d && filePtrs.back()->sd > d) return false;
    if (r && filePtrs.back()->sr > r) return false;

    if (!d) filePtrs.back()->ld = 1e18;
    else filePtrs.back()->ld = d;

    if (!r) filePtrs.back()->lr = 1e18;
    else filePtrs.back()->lr = r;

    return true;
}

void solve() {
    int n; cin >> n;
    string cmd;
    for (int i = 1; i <= n; i++) {
        cin >> cmd;
        if (cmd == "C") {
            if (create()) cout << "Y\n";
            else cout << "N\n";
        }
        else if (cmd == "R") {
            if (remove()) cout << "Y\n";
            else cout << "N\n";
        }
        else {
            if (modify()) cout << "Y\n";
            else cout << "N\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
