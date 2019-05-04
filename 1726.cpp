#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    long long xs[n];
    long long ys[n];
    long long total_distance = 0;
    for (long long i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }
    sort(xs, xs + n);
    sort(ys, ys + n);
    for (long long i = 1; i < n; ++i) {
        total_distance += (xs[i] - xs[i - 1]) * i * (n - i) * 2;
        total_distance += (ys[i] - ys[i - 1]) * i * (n - i) * 2;
    }
    cout << total_distance / (n * (n - 1));
}