


//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入：heights = [2,1,5,6,2,3]
//输出：10
//解释：最大的矩形为图中红色区域，面积为 10
// 
//
// 示例 2： 
//
// 
//
// 
//输入： heights = [2,4]
//输出： 4 
//
// 
//
// 提示： 
//
// 
// 1 <= heights.length <=10⁵ 
// 0 <= heights[i] <= 10⁴ 
// 
//
// Related Topics 栈 数组 单调栈 👍 2704 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int result = 0;
        stack<int> st;

        heights.insert(heights.begin(),0);
        heights.push_back(0); //两边必须要有个最小的，让其跳出前两个if 计算sum
        st.push(0);
        int sum =0;
        for (int i = 1; i < heights.size(); ++i) {
            if (heights[i] >= heights[st.top()]) {
                st.push(i);
            } else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                int mid = st.top();
                st.pop();
                    if (!st.empty()){
                        int left = st.top();
                        int right = i;
                        int w = right - left -1;
                        int h = heights[mid];
                        sum = w*h;
                        result = max(sum,result);
                    }

                }
                st.push(i);
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

