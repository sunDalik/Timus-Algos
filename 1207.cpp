#include <iostream>
#include <algorithm>

struct point {
    long long x;
    long long y;
    double angle;
    int num;

    bool operator<(point &other) { return angle < other.angle; }
};

using namespace std;

int main() {
    int n;
    cin >> n;
    point points[n];
    long long min_x = INT64_MAX;
    int min_i = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        points[i].x = x;
        if (x < min_x) {
            min_x = x;
            min_i = i;
        }
        cin >> points[i].y;
        points[i].num = i + 1;
    }

    for (point &p: points) {
        if (p.num == min_i + 1) {
            p.angle = INT32_MIN;
        } else if (p.x == points[min_i].x) {
            p.angle = (p.y > points[min_i].y) ? 90 : -90;
        } else {
            p.angle = (double) (p.y - points[min_i].y) / (p.x - points[min_i].x);
        }
    }
    cout << points[min_i].num << " ";
    sort(points, points + n);
    cout << points[n / 2].num;
}