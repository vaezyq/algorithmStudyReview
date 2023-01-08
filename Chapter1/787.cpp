//
// Created by 22126 on 2023/1/8.
//归并排序


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename Iterator, typename Func>
void merge(const Iterator &first, const Iterator &mi, const Iterator &last, const Func &func) {

    vector<typename Iterator::value_type> vec;
    auto start = first, start2 = mi;
    while (start != mi && start2 != last) {
        if (func(*start, *start2)) {
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
}


template<typename Iterator, typename Func>
void merge_sort(const Iterator &first, const Iterator &last, const Func &func) {
    if (distance(first, last) <= 1) { return; }   //当只有一个元素时递归结束
    auto len = distance(first, last);
    auto mi = first;
    advance(mi, len >> 1);
    merge_sort(first, mi, func);
    merge_sort(mi, last, func);
    merge(first, mi, last, func);
}


int main() {
    int n{0};
    vector<int> vec;
    scanf("%d", &n);
    generate_n(back_inserter(vec), n, [i = 0]() {
        scanf("%d", &i);
        return i;
    });
    merge_sort(vec.begin(), vec.end(), greater<>());

    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
    return 0;

}