//
// Created by 32894 on 2024-03-24.
//
#include <bits/stdc++.h>

int findMaxValue(int n){
    int bag = n;
    std::vector<int> weight = {1,3,4};
    std::vector<int> value = {15,20,30};
    std::vector<int> dp(n+1,0);
    dp[0] = 0;
    for (int i = 0;i<weight.size();i++) {
        for (int j = bag; j >= weight[i] ; --j) {
            dp[j] = std::max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    return dp[n];
}
int main(){
    int result = findMaxValue(4);
    std::cout<<"The max value result is :"<<result<<std::endl;
}
