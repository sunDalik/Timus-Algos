#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int a, b, l;
};

bool compare(edge a, edge b) {
    return a.l < b.l;
}

int find_parent(int x, int *parents) {
    if (parents[x] != x) parents[x] = find_parent(parents[x], parents);
    return parents[x];
}

int main() {
    int n, m, max_l = 0;
    cin >> n >> m;
    int parents[n];
    vector<edge> connections;
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        connections.push_back({a - 1, b - 1, l});
    }

    sort(connections.begin(), connections.end(), compare);

    int conn_counter = 0;
    for (int i = 0; i < n; i++) parents[i] = i;
    for (int i = 0; i < m; ++i) {
        int x = find_parent(connections[i].a, parents);
        int y = find_parent(connections[i].b, parents);
        if (x != y) {
            if (connections[i].l > max_l) max_l = connections[i].l;
            connections[i].l = -1;
            parents[x] = y;
            conn_counter++;
            if (conn_counter == n - 1) break;
        }
    }

    cout << max_l << "\n" << n - 1 << "\n";
    for (int i = 0; i < m; ++i) {
        if (connections[i].l == -1) {
            cout << connections[i].a + 1 << " " << connections[i].b + 1 << "\n";
        }
    }
    return 0;
}