




//给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。 
//
// 返回 你可以获得的最大乘积 。 
//
// 
//
// 示例 1: 
//
// 
//输入: n = 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。 
//
// 示例 2: 
//
// 
//输入: n = 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。 
//
// 
//
// 提示: 
//
// 
// 2 <= n <= 58 
// 
//
// Related Topics 数学 动态规划 👍 1358 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerBreak(int n) {
        /* 首先是定义dp数组：dp[i]代表整数i的最大分块乘积
         * dp[0]以及1是不需要定义的
         * 从最大值来看 dp[i] = max(dp[i],max((i-j)*j,dp[i-j]*j)) j从1开始遍历。前者代表2个数的直接组合，而后者由于是dp[i-j]*j 是三个数到三个数以上的组和
         */
        vector<int> dp(n+1);
        dp[2] = 1;
        for (int i = 3; i <=n ; ++i) {
            for (int j = 1; j < i ; ++j) {
                dp[i] = max(dp[i],max(dp[i-j]*j,(i-j)*j));
            }

        }
        return  dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

