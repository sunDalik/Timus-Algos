#include <iostream>
#include <bits/stdc++.h>

/**
 * Отсортируем все точки с левого верхнего угла по правый нижний: сначала строки, потом столбцы.
 * Каждую полосу, длиной больше 1 добавим в результат, каждую полосу, длиной 1 сохраним на будущее в вектор sq.
 *
 * Аналогично отсортируем все точки снова, только теперь сначала столбцы, потом строки.
 *
 * Теперь у нас есть количество вертикальных и горизонтальных полос. Осталось проверить только полосы 1х1.
 * Если полоса 1х1 встречается в векторе sq 2 раза, значит - квадрат 1х1 максимальен и по вертикали и по горизонтали
 * => его следует добавить в результат
 */

using namespace std;

bool compare1(pair<int, int> a, pair<int, int> b) {
    return (a.first != b.first) ? a.first < b.first : a.second < b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b) {
    return (a.second != b.second) ? a.second < b.second : a.first < b.first;
}

int main() {
    int m, n, k, result, strips = 0;
    cin >> m >> n >> k;
    vector<pair<int, int>> bad_days;
    vector<pair<int, int>> squares;
    for (int i = 0; i < k; ++i) {
        pair<int, int> day;
        cin >> day.first >> day.second;
        day.first--;
        day.second--;
        bad_days.push_back(day);
    }

    for (int i = 0; i < m; ++i) {
        pair<int, int> left_edge = {i, -1};
        pair<int, int> right_edge = {i, n};
        bad_days.push_back(right_edge);
        bad_days.push_back(left_edge);
    }

    for (int i = 0; i < n; ++i) {
        pair<int, int> top_edge = {-1, i};
        pair<int, int> bottom_edge = {m, i};
        bad_days.push_back(bottom_edge);
        bad_days.push_back(top_edge);
    }

    sort(bad_days.begin(), bad_days.end(), compare1);

    for (int i = 0; i < bad_days.size() - 1; ++i)
        if (bad_days[i].first == bad_days[i + 1].first) {
            if (bad_days[i + 1].second - (bad_days[i].second + 1) > 1) {
                strips++;
            } else if (bad_days[i + 1].second - (bad_days[i].second + 1) == 1) {
                squares.emplace_back(make_pair(bad_days[i].first, bad_days[i].second + 1));
            }
        }

    sort(bad_days.begin(), bad_days.end(), compare2);

    for (int i = 0; i < bad_days.size() - 1; ++i)
        if (bad_days[i].second == bad_days[i + 1].second) {
            if (bad_days[i + 1].first - (bad_days[i].first + 1) > 1) {
                strips++;
            } else if (bad_days[i + 1].first - (bad_days[i].first + 1) == 1) {
                squares.emplace_back(make_pair(bad_days[i].first + 1, bad_days[i].second));
            }
        }

    sort(squares.begin(), squares.end(), compare1);

    result = strips;
    if (squares.size() > 1)
        for (int i = 0; i < squares.size() - 1; ++i)
            if (squares[i] == squares[i + 1]) {
                result++;
                i++;
            }

    cout << result << endl;
    return 0;
}