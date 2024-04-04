




//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。 
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。 
//
// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,7,7,8,8,10,11,19,20], target = 8
//输出：[3,4] 
//
// 示例 2： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1] 
//
// 示例 3： 
//
// 
//输入：nums = [], target = 0
//输出：[-1,-1] 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// nums 是一个非递减数组 
// -10⁹ <= target <= 10⁹ 
// 
//
// Related Topics 数组 二分查找 👍 2662 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int searchBound(vector<int>& nums, int target){
        int low = 0;
        int right = nums.size()-1;

        while(low<=right){
            int mid = low+(right-low)/2;
            if(nums[mid]<target){
                low = mid+1;
            }else{
                right = mid-1;
            }
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {


        int start = searchBound(nums,target);
        if (start==nums.size()||nums[start]!=target){
            return {-1,-1};
        }
        int end = searchBound(nums,target+1)-1;
        return {start,end};
    }

};
//leetcode submit region end(Prohibit modification and deletion)

