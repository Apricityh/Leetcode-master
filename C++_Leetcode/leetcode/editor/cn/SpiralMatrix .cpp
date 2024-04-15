




//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。 
//
// 
//
// 示例 1： 
// 
// 
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
// 
// 
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 10 
// -100 <= matrix[i][j] <= 100 
// 
//
// Related Topics 数组 矩阵 模拟 👍 1659 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        vector<int> res;
        while(true){
            for (int i = l; i <=r ; ++i) {
                res.push_back(matrix[t][i]);
            }
            if (++t>b)break;
            for (int i = t; i <=b ; ++i) {
                res.push_back(matrix[i][r]);
            }
            if (l>--r)break;
            for (int i = r; i >=l ; --i) {
                res.push_back(matrix[b][i]);
            }
            if (t>--b) break;
            for (int i = b; i >=t ; --i) {
                res.push_back(matrix[i][l]);
            }
            if (++l>r)break;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

