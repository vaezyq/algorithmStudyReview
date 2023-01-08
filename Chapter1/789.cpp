//
// Created by 22126 on 2023/1/8.
//整数二分


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename Iterator, typename T>

std::optional<Iterator> get_start_pos(const Iterator &first, const Iterator &last, const T &ele) {
    auto left = first, right = last;
//    auto left = -1, right =
    advance(left, -1);

    while (distance(left, right) > 1) {
        auto mi = first;
        advance(mi, (distance(first, left) + distance(first, right)) >> 1);
        if (*mi < ele) {
            left = mi;
        } else {
            right = mi;
        }
    }
    if (right >= first && right < last) {
        if (*right == ele) {
            return {right};
        }
    }
    return std::nullopt;
}

template<typename Iterator, typename T>
std::optional<Iterator> get_end_pos(const Iterator &first, const Iterator &last, const T &ele) {
    auto left = first, right = last;
    advance(left, -1);
    while (distance(left, right) > 1) {
        auto mi = first;
        advance(mi, (distance(first, left) + distance(first, right)) >> 1);
        if (*mi <= ele) {
            left = mi;
        } else {
            right = mi;
        }
    }
    if (left >= first && left < last) {
        if (*left == ele) {
            return {left};
        }
    }
    return std::nullopt;
}


int main() {
    int n{0}, op{0}, nums{0};
    vector<int> vec;
    cin >> n >> op;
    generate_n(back_inserter(vec), n, [i = 0]() {
        scanf("%d", &i);
        return i;
    });
    while (op--) {
        cin >> nums;
        auto start = get_start_pos(vec.begin(), vec.end(), nums);
        cout << (start.has_value() ? distance(vec.begin(), start.value()) : -1) << " ";
        auto end = get_end_pos(vec.begin(), vec.end(), nums);
        cout << (end.has_value() ? distance(vec.begin(), end.value()) : -1) << endl;
    }

    return 0;
}