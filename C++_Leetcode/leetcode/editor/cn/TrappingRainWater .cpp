


//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 1 <= n <= 2 * 10⁴ 
// 0 <= height[i] <= 10⁵ 
// 
//
// Related Topics 栈 数组 双指针 动态规划 单调栈 👍 5105 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //暴力超时
//    int trap(vector<int>& height) {
//        if (height.size()==0){
//            return 0;
//        }
//        int sum = 0;
//        for (int i = 0; i < height.size(); ++i) {
//            if (i==0||i==height.size()-1) continue;
//            int heightl = height[i];
//            int heightr = height[i];
//            for (int j = i; j <height.size() ; ++j) {
//                heightr = max(heightr,height[j]);
//            }
//            for (int j = i; j >=0 ; --j) {
//                heightl = max(heightl,height[j]);
//              }
//            if (min(heightl,heightr)-height[i]>0){
//                sum+=min(heightl,heightr)-height[i];
//            }else{
//                continue;
//            }
//        }
//        return sum;
//    }

//单调栈
    int trap(vector<int> &height) {
        stack<int> st;//st.top()的左边的数一定高于它自己
        int sum = 0;
        st.push(0);
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] < height[st.top()]) {
                st.push(i);
            }else if(height[i]==height[st.top()]){
                st.pop();//相同则pop再放入，当前top一定小于左边某个数，直接pop
                st.push(i);
            }else{  //height[i] > height[st.top()]
                while(!st.empty()&&height[i]>height[st.top()]){   //每一个最小点仅仅是将自己和两边最小的差距空间计算了，st.top()的下面比它大，仍然需要计算
                    int mid = st.top();//记录此柱的下标 利用height[mid]
                    st.pop();//先弹出，留下左边最高的为st.top();
                    if (!st.empty()){  //左边有元素
                        int h = min(height[i],height[st.top()])-height[mid];
                        int w = i - st.top()-1;
                        sum+=w*h;
                    }
                }st.push(i);//当前最大push
            }
        }
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

