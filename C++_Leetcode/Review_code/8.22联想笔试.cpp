//
// Created by 32894 on 2024-08-22.
//
#include "iostream"
#include "vector"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> monster(n);
    int xst, yst, xed, yed;
    cin >> xst >> yst >> xed >> yed;
    //交叉向量积
    int count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> monster[i].first >> monster[i].second;
    }
    for (int i = 0; i < n; ++i) {
        int x = monster[i].first;
        int y = monster[i].second;
        //交叉积（叉积）是向量的一个重要运算，用于计算两个向量的垂直度量。在二维空间中，交叉积可以用来判断三个点是否共线。
        if ((x - xst) * (yed - yst) == (y - yst) * (xed - xst)) {
            //检查怪物是否在射线方向  防止反方向
            if ((x - xst) * (xed - xst) >= 0 && (y - yst) * (yed - yst) >= 0) {
                count++;
            }
        }
    }
    cout << count;
}
//#include "iostream"
//#include "vector"
//#include "unordered_set"
//#include "unordered_map"
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    long long n = s.size();
//    vector<long long > dp(n + 1, 0);
//    dp[0] = 1;
//    unordered_map<string,int> strings;
//    for (long long i = 1; i <= n; ++i) {
//        for (long long j = 0; j <i; ++j) {
//            string temp = s.substr(j, i - j);
//            int num = stoi(temp);
//            if ((strings.find(temp) == strings.end()||strings[temp]<j)&&num%4==0) {
//                dp[i] += dp[j];
//                strings[temp] = i;
//            }
//        }
//    }
//    cout << dp[n] << endl;
//    return 0;
//}