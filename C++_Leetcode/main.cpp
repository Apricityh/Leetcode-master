////ʵ�ִ�20����ѡȡ����1000����������С����
//#include <vector>
//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//std::vector<int> findMaxNum(const std::vector<int> &num, int k) {
//    std::priority_queue<int, std::vector<int>, std::greater<int>> minHap;
//    for (int i = 0; i < k; ++i) {
//        minHap.push(num[i]);
//    }
//    for (int i = k; i < num.size(); ++i) {
//        if (num[i] > minHap.top()) {
//            minHap.pop();
//            minHap.push(num[i]);
//        }
//    }
//    std::vector<int> result;
//    while (!minHap.empty()) {
//        int temp = minHap.top();
//        result.push_back(temp);
//        minHap.pop();
//    }
//    return result;
//}
//
//int main() {
//    std::vector<int> number;
//    for (int i = 0; i < 2000000; ++i) {
//        number.push_back(i);
//    }
//    std::vector<int> result = findMaxNum(number,1000);
//    for (auto num:result) {
//        cout<<num<<endl;
//    }
//    return 0;
//}


#include<bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

int countSubstrings(const string& str) {
    int count = 0;
    int len = str.length();

    for (int i = 0; i < len; ++i) {
        if (str[i] == 'd') continue;

        int j = i;
        bool hasR = false;
        bool hasE = false;

        while (j < len && str[j] != 'd') {
            if (str[j] == 'r') {
                hasR = true;
            } else if (str[j] == 'e') {
                hasE = true;
            }

            if (hasR && hasE) {
                ++count;
            }

            ++j;
        }
    }

    return count;
}

int main() {
    string str = "abcdefghierjkerlskemrnlest";
    int result = countSubstrings(str);
    cout << "Number of substrings: " << result << endl;
    return 0;
}
