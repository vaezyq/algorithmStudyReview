//
// Created by 22126 on 2023/1/8.
// 高精度减法

#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <memory>

using namespace std;


bool greater_num(const string &a, const string &b) {
    if (a.size() > b.size()) {
        return true;
    } else if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] < b[i]) {
                return false;
            } else if (a[i] > b[i]) {
                return true;
            }
        }
        return true;
    } else {
        return false;
    }

}


std::shared_ptr<vector<int>> substract_big_num(const vector<int> &num, const vector<int> &num2) {

    auto res = std::make_shared<vector<int>>();
    int sub = 0;
    auto start = num.begin(), start2 = num2.begin();


    for (; start2 != num2.end(); advance(start2, 1), advance(start, 1)) {
        auto temp = *start - *start2 - sub;
        if (temp < 0) {
            sub = 1;
            temp += 10;
        } else {
            sub = 0;
        }
        res->emplace_back(temp);
    }
    while (start != num.end()) {
        auto temp = *start - sub;
        if (temp < 0) {
            sub = 1;
            temp += 10;
        } else {
            sub = 0;
        }
        res->emplace_back(temp);
        advance(start, 1);
    }
    while (res->size() > 1 && (*(res->end() - 1) == 0)) {
        res->pop_back();
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

    if (greater_num(a, b)) {
        auto res = substract_big_num(num, num2);
        for_each(res->rbegin(), res->rend(), [](int i) { cout << i; });
    } else {
        cout << "-";
        auto res = substract_big_num(num2, num);
        for_each(res->rbegin(), res->rend(), [](int i) { cout << i; });
    }

    return 0;
}