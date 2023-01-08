//
// Created by 22126 on 2023/1/8.
// 逆序对的数量

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename Iterator, typename Func>
unsigned merge(const Iterator &first, const Iterator &mi, const Iterator &last, const Func &func) {
    unsigned count{0};
    vector<typename Iterator::value_type> vec;
    auto start = first, start2 = mi;
    while (start != mi && start2 != last) {
        if (func(*start, *start2)) {
            count += (mi - start);
            vec.emplace_back(*start2);
            advance(start2, 1);
        } else {
            vec.emplace_back(*start);
            advance(start, 1);
        }
    }
    while (start != mi) {
        vec.emplace_back(*start);
        advance(start, 1);
    }
    while (start2 != last) {
        vec.emplace_back(*start2);
        advance(start2, 1);
    }
    copy(vec.begin(), vec.end(), first);
    return count;
}

template<typename Iterator, typename Func>
unsigned calculate_reverse_order_nums(const Iterator &first, const Iterator &last, const Func &func) {
    if (distance(first, last) <= 1) { return 0; }
    int res = 0;
    auto len = distance(first, last);
    auto mi = first;
    advance(mi, len >> 1);
    res += calculate_reverse_order_nums(first, mi, func);
    res += calculate_reverse_order_nums(mi, last, func);
    res += merge(first, mi, last, func);
    return res;
}


int main() {
    int n{0};
    vector<int> vec;
    scanf("%d", &n);
    generate_n(back_inserter(vec), n, [i = 0]() {
        scanf("%d", &i);
        return i;
    });
    cout << calculate_reverse_order_nums(vec.begin(), vec.end(), greater<>());
    return 0;
}




