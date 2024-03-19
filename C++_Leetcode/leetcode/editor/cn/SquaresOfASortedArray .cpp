


//给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
//
// 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-4,-1,0,3,10]
//输出：[0,1,9,16,100]
//解释：平方后，数组变为 [16,1,0,9,100]
//排序后，数组变为 [0,1,9,16,100] 
//
// 示例 2： 
//
// 
//输入：nums = [-7,-3,2,3,11]
//输出：[4,9,9,49,121]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// nums 已按 非递减顺序 排序 
// 
//
// 
//
// 进阶： 
//
// 
// 请你设计时间复杂度为 O(n) 的算法解决本问题 
// 
//
// Related Topics 数组 双指针 排序 👍 818 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
//

        int n = nums.size() - 1;
        int k = nums.size() -1;
        vector<int> result(nums.size(), 0);
        int start = 0;
        while (start <= n) {
            if (nums[start] * nums[start] < nums[n] * nums[n]) {
                result[k--] = nums[n] * nums[n];
                n--;
            } else {
                result[k--] = nums[start] * nums[start];
                start++;
            }
        }
 //       result[k] = nums[start] * nums[start];
        return result;

    }

};
//leetcode submit region end(Prohibit modification and deletion)
//        vector<int> ans;
//        for (int i:nums) {
//            ans.push_back(i*i);
//        }
//        sort(ans.begin(),ans.end());
//        return ans;   //采用的栈



