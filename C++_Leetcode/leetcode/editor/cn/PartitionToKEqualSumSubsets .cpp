




//给定一个整数数组 nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。 
//
// 
//
// 示例 1： 
//
// 
//输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
//输出： True
//说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。 
//
// 示例 2: 
//
// 
//输入: nums = [1,2,3,4], k = 3
//输出: false 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= len(nums) <= 16 
// 0 < nums[i] < 10000 
// 每个元素的频率在 [1,4] 范围内 
// 
//
// Related Topics 位运算 记忆化搜索 数组 动态规划 回溯 状态压缩 👍 1020 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int> dp(10000*16/3+1,0);
            int sum = 0;
            int target = 0;
        for (auto i:nums) {
            sum+=i;
        }
        cout<<sum<<endl;
        if (sum%k!=0){
            return false;
        }else{
            target = sum/k;
        }
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >=nums[i] ; --j) {
                dp[j]= max(dp[j],dp[j-nums[i]]+nums[i]);
            }
        }
        if (dp[target]==target){
            return true;
        }
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

