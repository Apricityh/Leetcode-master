


//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。 
//
// 
//
// 示例 1: 
//
// 
//输入: [3,2,1,5,6,4], k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 
//输入: [3,2,3,1,2,4,5,5,6], k = 4
//输出: 4 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
//
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 2434 👎 0


#include<bits/stdc++.h>
#include<queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    int part(vector<int> &nums, int left, int right) {
//        int index = left + (right - left) / 2;
//        int mid = nums[index];
//        int i = left - 1;
//        int j = right + 1;
//        while (true) {
//            do {
//                i++;
//            } while (nums[i] < mid);
//            do {
//                j--;
//            } while (nums[j] > mid);
//            if (i >= j) {
//                return j;
//            }
//            swap(nums[i], nums[j]);
//        }
//
//    }
//
//    void quick(vector<int> &nums, int left, int right) {
//        if (left < right) {
//            int mid = part(nums, left, right);
//            quick(nums, left, mid);
//            quick(nums, mid + 1, right);
//        }
//    }

    int findKthLargest(vector<int> &nums, int k) {
//    quick(nums, 0, nums.size() - 1);
//        for (int i: nums) {
//            cout << i;
//        }
//        return nums[nums.size() - k];
//    }
//        priority_queue<int,vector<int>> queue;
//        for (int i = 0; i < nums.size(); ++i) {
//            queue.push(nums[i]);
//        }
//        int temp = 0;
//        for (int i = 0; i < k; ++i) {
//            temp = queue.top();
//            queue.pop();
//        }
//        return temp;

}};
//leetcode submit region end(Prohibit modification and deletion)

