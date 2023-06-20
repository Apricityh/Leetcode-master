


//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [0,1,0,3,12]
//输出: [1,3,12,0,0]
// 
//
// 示例 2: 
//
// 
//输入: nums = [0]
//输出: [0] 
//
// 
//
// 提示: 
// 
//
// 
// 1 <= nums.length <= 10⁴ 
// -2³¹ <= nums[i] <= 2³¹ - 1 
// 
//
// 
//
// 进阶：你能尽量减少完成的操作次数吗？ 
//
// Related Topics 数组 双指针 👍 2039 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int low = 0;
        int high = 0;
        while (high < nums.size()) {
            {
                if (nums[high] != 0) {
                    nums[low] = nums[high];
                    low++;//指向最新不为0数组的下一个位置，方便后续找到不为0 的数字直接复制过来
                }
                high++;
            }
        }
        for (int i = low; i <nums.size() ; ++i) {
            nums[i] = 0;

        }
    }


};
//leetcode submit region end(Prohibit modification and deletion)

