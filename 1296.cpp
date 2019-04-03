#include <iostream>

using namespace std;

int main() {
    int length;
    cin >> length;
    int seq = 0;
    int max_p = 0;
    for (int i = 0; i < length; ++i) {
        int p;
        cin >> p;
        seq += p;
        if (seq < 0) seq = 0;
        if (seq > max_p) max_p = seq;
    }

    cout << max_p;
}