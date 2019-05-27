#include <iostream>
#include <vector>

//??????????????????????????????????????????????????????????????????

using namespace std;

struct exchange_operation {
    int a, b;
    double r, c;
};

vector<exchange_operation> exchange_operations;
double nd[110];

int main() {
    int n, m, s;
    double v;
    cin >> n >> m >> s >> v;
    nd[s] = v;
    for (int i = 0; i < m; ++i) {
        int a, b;
        double rab, cab, rba, cba;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        exchange_operations.push_back({a, b, rab, cab});
        exchange_operations.push_back({b, a, rba, cba});
    }

    for (int i = 0; i < n - 1; ++i) {
        for (auto &j : exchange_operations) {
            if ((nd[j.a] - j.c) * j.r - nd[j.b] > 0.00001) {
                nd[j.b] = (nd[j.a] - j.c) * j.r;
            }
        }
    }

    for (auto &i : exchange_operations) {
        if ((nd[i.a] - i.c) * i.r - nd[i.b] > 0.00001) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}