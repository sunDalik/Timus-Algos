#include <iostream>
#include <vector>

using namespace std;

struct pipeline {
    int a, b, c;
};

vector<pipeline> v;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> res(510, -1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a - 1, b - 1, c});
    }
    int s, f;
    cin >> s >> f;
    res[s - 1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (res[v[j].a] != -1 && res[v[j].b] < res[v[j].a] + v[j].c) {
                res[v[j].b] = res[v[j].a] + v[j].c;
            }
        }
    }

    if (res[f - 1] != -1) cout << res[f - 1];
    else cout << "No solution";
    return 0;
}