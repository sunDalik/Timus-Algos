#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

void shift_signs_value(pair<int, int> *signs, int n, int i) {
    int j = i + 1;
    while (signs[i].second < signs[j].second) {
        swap(signs[i], signs[j]);
        i++, j++;
        if (j == n) break;
    }
}

int main() {
    int n = 0;
    cin >> n;
    pair<int, int> signs[n]; //<index, number of signs left>
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        cin >> x;
        sum += x;
        signs[i] = make_pair(i + 1, x);
    }
    sort(signs, signs + n, comp);
    while (sum--) {
        cout << signs[0].first << " ";
        signs[0].second--;
        if (n > 1 && signs[1].second > 0) {
            cout << signs[1].first << " ";
            signs[1].second--;
            sum--;
        }
        if (n > 2) shift_signs_value(signs, n, 1);
        if (n > 1) shift_signs_value(signs, n, 0);
    }
}