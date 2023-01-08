//
// Created by 22126 on 2023/1/8.
// 第k个数
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


template<typename Iterator, typename Func>
Iterator partition_lug(const Iterator &first, const Iterator &last, const Func &func) {
    auto mi = first;
    auto pivot = first;  //选取头结点作为轴点

    swap(*first, *(first + rand() % (0, distance(first, last)))); //做随机交换，等于随机选取

    auto start = first;
    advance(start, 1);          //从first+1开始对容器所有元素进行遍历

    //保证[pivot=first]是轴点,(first,mi]中的元素都小于等于基准元素[pivot],(mi,k)中的元素都大于等于基准元素[pivot]
    //[k,last)中的元素是还没有操作到的元素
    std::for_each(start, last, [&mi, &pivot](int &a)mutable {
        if (a < *pivot) {  //当小于基准元素时，做交换操作
            advance(mi, 1);
            swap(*mi, a);
        }
    });
    swap(*pivot, *mi);   //基准元素归位，这是为了保证基准元素一定位于mi处
    return mi;
}


template<typename Iterator, typename Func>
Iterator select_k_th(const Iterator &start, const Iterator &first, const Iterator &last, const Func &func,
                     const unsigned &k) {     //选取第k小的数字

    auto mi = partition_lug(first, last, func);

    if ((distance(start, mi) + 1) == k) {
        return mi;
    } else if ((distance(start, mi) + 1) < k) {
        return select_k_th(start, mi + 1, last, func, k);
    } else {
        return select_k_th(start, first, mi, func, k);
    }
}


int main() {
    auto n = 0, k = 0;
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> vec;
    cin >> n >> k;
    generate_n(back_inserter(vec), n, [x = 0]()mutable {
        cin >> x;
        return x;
    });
    cout << *select_k_th(vec.begin(), vec.begin(), vec.end(), greater<>(), k);
    return 0;
}


