


//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j !=
//k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请 
//
// 你返回所有和为 0 且不重复的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
//注意，输出的顺序和三元组的顺序并不重要。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,1]
//输出：[]
//解释：唯一可能的三元组和不为 0 。
// 
//
// 示例 3： 
//
// 
//输入：nums = [0,0,0]
//输出：[[0,0,0]]
//解释：唯一可能的三元组和为 0 。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 3000 
// -10⁵ <= nums[i] <= 10⁵ 
// 
//
// Related Topics 数组 双指针 排序 👍 6145 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
//        //放答案的三元组
//        vector<vector<int>> result;
//        sort(nums.begin(), nums.end());
//        for (int i = 0; i < nums.size(); ++i) {
//            if (nums[i] > 0) {
//                return result;
//            }
//            if (i > 0 && nums[i] == nums[i - 1]) {
//                continue;   //跳过，因为与i-1相等的情况下，合适的元组已经被挑选出来了
//            }
//            int left = i + 1;
//            int right = nums.size() - 1;
//            while (left < right) {
//                if (nums[i] + nums[left] + nums[right] < 0) left++;
//                else if (nums[i] + nums[left] + nums[right] > 0) right--;
//                else {
//                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});//将结果压入二元组
//                    while (right > left && nums[left] == nums[left + 1]) { left++; } //去重
//                    while (right > left && nums[right] == nums[right - 1]) { right--; }//去重
//                    left++;
//                    right--;
//                }
//            }
//
//        }
//        return result;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]>0)return res;
            if (i>0&&nums[i]==nums[i-1])continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                if (nums[i]+nums[left]+nums[right]>0) right--;
                else if (nums[i]+nums[left]+nums[right]<0) left++;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (left<right&&nums[left] == nums[left + 1])left++;
                    while (left<right&&nums[right] == nums[right -1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

