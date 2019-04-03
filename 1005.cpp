#include <iostream>
#include <algorithm>

/*
У вас есть несколько камней известного веса w1, …, wn. Напишите программу, которая распределит камни в две кучи так, что разность весов этих двух куч будет минимальной.
Ввод содержит количество камней n (1 ≤ n ≤ 20) и веса камней w1, …, wn (1 ≤ wi ≤ 100 000) — целые, разделённые пробельными символами.
Ваша программа должна вывести одно число — минимальную разность весов двух куч.
*/

using namespace std;

int f(int array[], int array_length, int i = 0, int sum1 = 0, int sum2 = 0) {
    if (i == array_length) {
        return abs(sum1 - sum2);
    } else {
        int min_diff1 = f(array, array_length, i + 1, sum1 + array[i], sum2);
        int min_diff2 = f(array, array_length, i + 1, sum1, sum2 + array[i]);
        return min(min_diff1, min_diff2);
    }
}

int main() {
    int stone_length;
    cin >> stone_length;
    int stone_array[stone_length];
    for (int i = 0; i < stone_length; ++i) {
        cin >> stone_array[i];
    }

    cout << f(stone_array, stone_length);
}

