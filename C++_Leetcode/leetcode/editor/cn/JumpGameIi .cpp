


//给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
//
// 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处: 
//
// 
// 0 <= j <= nums[i] 
// i + j < n 
// 
//
// 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [2,3,1,1,4]
//输出: 2
//解释: 跳到最后一个位置的最小跳跃数是 2。
//     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 
//
// 示例 2: 
//
// 
//输入: nums = [2,3,0,1,4]
//输出: 2
// 
//
// 
//
// 提示: 
//
// 
// 1 <= nums.length <= 10⁴ 
// 0 <= nums[i] <= 1000 
// 题目保证可以到达 nums[n-1] 
// 
//
// Related Topics 贪心 数组 动态规划 👍 2283 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/*
 * 考虑现在最远步长以及下一步最远步长
 * 若遍历的数据到了当前最远能覆盖的距离，那就更新移动步数，同时更新当前覆盖范围和下一步覆盖范围。
 * */
class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size()==1){
            return 0;
        }
        int curCover = 0;
        int ans = 0;//步数
        int nextCover = 0;
        for (int i = 0; i < nums.size(); ++i) {
            nextCover = max(i + nums[i], nextCover);
            if (i == curCover) {//
                ans++;
                curCover = nextCover;
                if (curCover >= nums.size() - 1) {
                    break;
                }
            }
        }
        return ans;


    }
};
//leetcode submit region end(Prohibit modification and deletion)

