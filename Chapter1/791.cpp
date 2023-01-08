//
// Created by 22126 on 2023/1/8.
//高精度加法

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory>

using namespace std;

std::shared_ptr<vector<int>> plus_big_num(const vector<int> &num, const vector<int> &num2) {
    auto res = std::make_shared<vector<int>>();

    int carry = 0;
    auto start = num.begin(), start2 = num2.begin();
    for (; start < num.end() && start2 < num2.end(); advance(start, 1), advance(start2, 1)) {
        auto temp = *start + *start2 + carry;
        carry = temp / 10;
        res->emplace_back(temp % 10);
    }
    while (start < num.end()) {
        auto temp = *start + carry;
        carry = temp / 10;
        res->emplace_back(temp % 10);
        advance(start, 1);
    }
    while (start2 < num2.end()) {
        auto temp = *start2 + carry;
        carry = temp / 10;
        res->emplace_back(temp % 10);
        advance(start2, 1);
    }
    if (carry) {
        res->emplace_back(carry);
    }

    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> num, num2;
    transform(a.rbegin(), a.rend(), back_inserter(num), [](char c) {
        return c - '0';
    });   //倒序存储
    transform(b.rbegin(), b.rend(), back_inserter(num2), [](char c) {
        return c - '0';
    });   //倒序存储

    auto res = plus_big_num(num, num2);
    for_each(res->rbegin(), res->rend(), [](int i) { cout << i; });
    return 0;
}