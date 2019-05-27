#include <iostream>
#include <map>

using namespace std;

struct tree {
    string name;
    map<string, tree *> children;

    tree() {
        this->name = "";
        this->children = {};
    }

    tree(string name) {
        this->name = name;
        this->children = {};
    }
};

void print_tr(tree *tr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        cout << " ";
    }
    if (!tr->name.empty()) {
        cout << tr->name << endl;
    }
    ++n;
    for (auto &j : tr->children) {
        print_tr(j.second, n);
    }
}

int main() {
    int n = 0;
    cin >> n;

    tree *tr_root = new tree();

    for (int i = 0; i < n; ++i) {
        string path;
        cin >> path;
        string dir;

        tree *tr = tr_root;
        for (int j = 0; j <= path.size(); ++j) {
            if (path[j] == '\\' || path[j] == '\0') {
                auto dir_tr = tr->children.find(dir);
                if (dir_tr == tr->children.end()) {
                    tr->children[dir] = new tree(dir);
                    tr = tr->children.find(dir)->second;
                } else {
                    tr = dir_tr->second;
                }
                dir = "";
            } else {
                dir += path[j];
            }
        }
    }
    print_tr(tr_root, 0);
    return 0;
}