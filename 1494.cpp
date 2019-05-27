#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    stack<int> balls;
    int tmp_max = 0;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        if (cur > tmp_max) {
            for (int j = tmp_max + 1; j < cur; j++) {
                balls.push(j);
            }
            tmp_max = cur;
        } else {
            if (cur == balls.top()){
                balls.pop();
            } else {
                cout << "Cheater";
                return 0;
            }
        }
    }
    cout << "Not a proof";
    return 0;
}