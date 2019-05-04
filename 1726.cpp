#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long xs[n];
    long long ys[n];
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }
    sort(xs, xs + n);
    sort(ys, ys + n);
    for (long long i = 1; i < n; ++i) {
        sum += (xs[i] - xs[i - 1]) * i * (n - i);
        sum += (ys[i] - ys[i - 1]) * i * (n - i);
    }
    cout << 2 * sum / (n * (n - 1));
}