//
// Created by 32894 on 2024-03-19.
//
//实现从20亿中选取最大的1000个数，采用小顶堆
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
std::vector<int> findMaxNum(const std::vector<int> &num, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHap;
    //std::priority_queue<int> maxHap; 大顶堆
    for (int i = 0; i < k; ++i) {
        minHap.push(num[i]);
    }
    for (int i = k; i < num.size(); ++i) {
        if (num[i] > minHap.top()) {
            minHap.pop();
            minHap.push(num[i]);
        }
    }
    std::vector<int> result;
    while (!minHap.empty()) {
        int temp = minHap.top();
        result.push_back(temp);
        minHap.pop();
    }
    return result;
}

int main() {
    std::vector<int> number;
    for (int i = 0; i < 2000000; ++i) {
        number.push_back(i);
    }
    std::vector<int> result = findMaxNum(number,1000);
    for (auto num:result) {
        cout<<num<<endl;
    }
    return 0;
}
