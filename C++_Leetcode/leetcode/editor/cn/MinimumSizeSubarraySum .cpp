


//给定一个含有 n 个正整数的数组和一个正整数 target 。
//
// 找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长
//度。如果不存在符合条件的子数组，返回 0 。 
//
// 
//
// 示例 1： 
//
// 
//输入：target = 7, nums = [2,3,1,2,4,3]
//输出：2
//解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 
//
// 示例 2： 
//
// 
//输入：target = 4, nums = [1,4,4]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：target = 11, nums = [1,1,1,1,1,1,1,1]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= target <= 10⁹ 
// 1 <= nums.length <= 10⁵ 
// 1 <= nums[i] <= 10⁵ 
// 
//
// 
//
// 进阶： 
//
// 
// 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。 
// 
//
// Related Topics 数组 二分查找 前缀和 滑动窗口 👍 1737 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//暴力破解是不行
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int result = INT32_MAX;
        int i = 0;
        int sum = 0;
        for (int j = 0; j < nums.size(); ++j) {
            sum+=nums[j];
            while(sum>=target){
                result = min(result,j-i+1);
                sum-=nums[i++];
            }

        }
        return result==INT32_MAX?0:result;








 //滑动窗口，时间复杂度是o(n)
//        int result = INT32_MAX;//暂放最长序列的大小
//        int n = nums.size();
//        int i = 0;//滑动窗口的起始
//        int length = 0;//滑动窗口的大小
//        int sum = 0;
//        for (int j = 0; j < n; ++j) {
//             sum+= nums[j];
//             while(sum>=target)//不断缩小滑动窗口的大小，以及更新其长度
//             {
//              result = min(result,j-i+1);
//              sum-=nums[i++];//更新滑动窗口
//             }
//        }
//        return result==INT32_MAX?0: result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

