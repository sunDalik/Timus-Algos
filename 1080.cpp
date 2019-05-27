#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int countries[100]; // -1 = not visited, 0 = red, 1 = blue
vector<int> borders[100];

void paint_boundary_countries(int ct_i) {
    for (int i = 0; i < borders[ct_i].size(); ++i) {
        int bct_i = borders[ct_i][i];
        if (countries[bct_i] == -1) {
            countries[bct_i] = countries[ct_i] == 0 ? 1 : 0;
            paint_boundary_countries(bct_i);
        } else if (countries[ct_i] == countries[bct_i]) {
            cout << "-1";
            exit(0);
        }
    }
}

int main() {
    int n;
    cin >> n;
    fill_n(countries, 100, -1);
    countries[0] = 0;
    for (int i = 0; i < n; ++i) {
        int b = -1;
        while (b != 0) {
            cin >> b;
            if (b != 0) {
                borders[i].push_back(b - 1);
                borders[b - 1].push_back(i);
            }
        }
    }

    paint_boundary_countries(0);

    for (int i = 1; i < n; ++i) {
        if (countries[i] == -1) paint_boundary_countries(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << countries[i];
    }
    return 0;
}