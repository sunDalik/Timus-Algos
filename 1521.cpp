#include <iostream>

using namespace std;

int n, k;
int fenwick_tree_arr[100000];

int sum(int a) {
    int s = 0;
    for (; a >= 0; a = (a & (a + 1)) - 1) {
        s += fenwick_tree_arr[a];
    }
    return s;
}

int segment_sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void update_status(int a) {
    for (; a < n; a = (a | (a + 1))) {
        fenwick_tree_arr[a]++;
    }
}

int fetch_next_deserter(int l_bound) {
    int deserter_num = k;
    while (deserter_num > 0) {
        int r_bound = (l_bound + deserter_num) % n;
        l_bound = (l_bound + 1) % n;
        if (l_bound <= r_bound)
            deserter_num = segment_sum(l_bound, r_bound);
        else
            deserter_num = segment_sum(l_bound, n - 1) + segment_sum(0, r_bound);
        l_bound = r_bound;
    }
    return l_bound;
}

int main() {
    cin >> n >> k;
    cout << k << " ";
    int a = k - 1;
    for (int i = 1; i < n; i++) {
        update_status(a);
        a = fetch_next_deserter(a);
        cout << a + 1 << " ";
    }
    return 0;
}