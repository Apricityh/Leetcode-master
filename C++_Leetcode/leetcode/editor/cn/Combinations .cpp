




//给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。 
//
// 你可以按 任何顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, k = 2
//输出：
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
//
// 示例 2： 
//
// 
//输入：n = 1, k = 1
//输出：[[1]] 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 1 <= k <= n 
// 
//
// Related Topics 回溯 👍 1490 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;

public:
    void backTraking(int n ,int k,int index){
        if (path.size()==k){
            result.push_back(path);
            //返回
            return;
        }
        for (int i = index; i <= n; ++i) {
            path.push_back(i);
            //递归
            backTraking(n,k,i+1);
            //回溯  无论是对1.2.3.4 还是  2.3.4   第一行，第二行 依次递归
            path.pop_back();
        }

        return;

    }
    vector<vector<int>> combine(int n, int k) {
            path.clear();
            result.clear();
            backTraking(n,k,1);
            return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

