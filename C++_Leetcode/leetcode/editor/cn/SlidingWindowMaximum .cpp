


//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
//。 
//
// 返回 滑动窗口中的最大值 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], k = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 1 <= k <= nums.length 
// 
//
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 👍 2401 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    class MyQueue {//单调队列
    public:
        deque<int> que;
        void pop(int val) {
            if (!que.empty() && que.front() == val) {
                que.pop_front();
            }
        }

        void push(int val) {
            while (!que.empty()&&val > que.back()) {   //将小于插入元素的值都弹出，保证队头是最大的数。
                que.pop_back();

            }
            que.push_back(val);
        }
        int front(){
            return que.front();//返回队头元素
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
            MyQueue que;
            vector<int> result;
        for (int i = 0; i < k; ++i) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i <nums.size() ; ++i) {
            que.pop(nums[i-k]);//先看能不能满足弹出最开始的那个元素  万一是 3 2 1 开头这样
            que.push(nums[i]);  // 把紧接着的一位传入进去。
            result.push_back(que.front());
        }
        return result;
     }
};
//leetcode submit region end(Prohibit modification and deletion)

