




//给你一个整数数组 nums，请你将该数组升序排列。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,2,3,1]
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：nums = [5,1,1,2,0,0]
//输出：[0,0,1,1,2,5]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 5 * 10⁴ 
// -5 * 10⁴ <= nums[i] <= 5 * 10⁴ 
// 
//
// Related Topics 数组 分治 桶排序 计数排序 基数排序 排序 堆（优先队列） 归并排序 👍 983 👎 0

//快排
#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int part(vector<int>& nums, int left, int right) {
        int mid = left + (right - left) / 2; // 使用中间数作为枢纽
        int pivot = nums[mid];
        int i = left - 1;
        int j = right + 1;
        while (true) {//212 122
            do {
                i++;
            } while (nums[i] < pivot);
            do {
                j--;
            } while (nums[j] > pivot);
            if (i >= j) {
                return j;
            }
            swap(nums[i], nums[j]);
        }
    }

    void quick(vector<int>& nums, int left, int right) {
        if (left < right) {
            int partitionIndex = part(nums, left, right);
            quick(nums, left, partitionIndex);
            quick(nums, partitionIndex+1 , right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        quick(nums, 0, nums.size() - 1);
        return nums;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

