#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct pipeline {
    int a, b, c;
};

vector<pipeline> pipes;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> profit(n, -1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        pipes.push_back({a - 1, b - 1, c});
    }
    int s, f;
    cin >> s >> f;
    profit[s - 1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (profit[pipes[j].a] != -1 && profit[pipes[j].b] < profit[pipes[j].a] + pipes[j].c) {
                profit[pipes[j].b] = profit[pipes[j].a] + pipes[j].c;
            }
        }
    }

    if (profit[f - 1] != -1) cout << profit[f - 1];
    else cout << "No solution";
    return 0;
}