//
// Created by 22126 on 2023/1/8.
// 快速排序
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
void quick_sort(const Iterator &first, const Iterator &last, const Func &func) {  //对[first,last)之间的元素排序
    if (distance(first, last) < 1) { return; }      //当元素个数只有一个时迭代结束

    auto mi = partition_lug<>(first, last, func);     //调用分区函数

    if (mi == first) {  //当调用分区后发现基准元素还是first位置处，就要判断是否出现最坏情况:[first,last)内元素都相等
        if (all_of(first, last, [num = *first](int a) { return num == a; })) {
            return;
        }
    }

    quick_sort(first, mi, func);
    quick_sort((advance(mi, 1), mi), last, func);
}


int main() {
    auto n = 0;
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> vec;
    cin >> n;
    generate_n(back_inserter(vec), n, [x = 0]()mutable {
        cin >> x;
        return x;
    });
    quick_sort(vec.begin(), vec.end(), greater<>());
    for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
}


