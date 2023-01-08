//
// Created by 22126 on 2023/1/8.
//浮点数二分

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double get_cube_root(double x) {
    double start = -1e4, end = 1e4;
    double mi = 0;
    do {
        mi = (start + end) / 2.0;
        if (mi * mi * mi < x) {
            start = mi;
        } else {
            end = mi;
        }
    } while (end - start >= 1e-7);
    return mi;
}


int main() {
    double num{0};
    cin >> num;

    cout << setiosflags(ios::fixed) << setprecision(6);
    cout << get_cube_root(num) << endl;
    return 0;
}