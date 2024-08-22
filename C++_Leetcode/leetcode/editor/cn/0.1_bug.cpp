//
// Created by 32894 on 2024-03-24.
//
//#include <bits/stdc++.h>
//
//int findMaxValue(int n){
//    int bag = n;
//    std::vector<int> weight = {1,3,4};
//    std::vector<int> value = {15,20,30};
//    std::vector<int> dp(n+1,0);
//    dp[0] = 0;
//    for (int i = 0;i<weight.size();i++) {
//        for (int j = bag; j >= weight[i] ; --j) {
//            dp[j] = std::max(dp[j],dp[j-weight[i]]+value[i]);
//        }
//    }
//    return dp[n];
//}
//int main(){
//    int result = findMaxValue(4);
//    std::cout<<"The max value result is :"<<result<<std::endl;
//}
#include <bits/stdc++.h>

using namespace std;

int n, bagweight;// bagweight代表行李箱空间
void solve() {
    vector<int> weight(n, 0); // 存储每件物品所占空间
    vector<int> value(n, 0);  // 存储每件物品价值
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for (int j = 0; j < n; ++j) {
        cin >> value[j];
    }
    vector<vector<int>> dp(weight.size(),vector<int>(bagweight+1,0));
    //初始化，将0号物品放置在背包里
    for (int i = weight[0]; i <= bagweight; ++i) {
        dp[0][i] = value[0];
    }
    //开始遍历物品和背包
    for (int i = 1; i < weight.size() ; ++i) {
        for (int j = 0; j <=bagweight; ++j) {
            if (weight[i]>j) dp[i][j] = dp[i-1][j];//沿用
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
        }
    }
    cout<<dp[weight.size()-1][bagweight];


}
int main(){
    while(cin>>n>>bagweight){
        solve();}
    return 0;
}