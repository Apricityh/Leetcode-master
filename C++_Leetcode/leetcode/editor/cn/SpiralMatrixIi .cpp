




//给你一个正整数 n ，生成一个包含 1 到 n² 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
//
// Related Topics 数组 矩阵 模拟 👍 1230 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,0));
        int x = 0;
        int y = 0;
        int offset = 1;
        int count = 1;
        int loop = n/2;
        int i,j;
        while(loop--){
            i = x;
            j = y;
            for (; j< n-offset; ++j) {
                result[i][j] = count++;
            }
            for (;i < n-offset; ++i) {
                result[i][j] = count++;
            }
            for (; j > y ; j--) {
                result[i][j] = count++;
            }
            for (; i > x; --i) {
                result[i][j] = count++;
            }
            x++;
            y++;
            offset++;
        }
        if (n/2){
            int mid = n/2;
            result[mid][mid] = count++;
        }
        return result;
//    vector<vector<int>> result(n,vector<int>(n,0));
//    int startx = 0; //记录第一个元素的位置
//    int starty = 0;
//    int loop = n/2;//记录圈数，每一圈缩小一半的数量
//    int offset = 1;//为了不处理最后这个元素。   （选择左闭右开）
//    int count = 1;
//    int i,j;
//    while(loop--){
//        i = startx;
//        j = starty;
//        for ( j = starty; j < n-offset  ; ++j) {
//            result[startx][j] = count++;
//        }
//        for ( i = startx ; i < n-offset ; ++i) {
//            result[i][j] = count++;
//        }
//        for (;j>starty;j--) {
//            result[i][j] = count++;
//        }
//        for ( ; i > startx ; i--) {
//            result[i][j] = count++;
//        }
//        startx++;
//        starty++;
//        offset+=1;//这里没想到，因为第二个循环需要往前进一个位置
//    }
//        if (n%2!=0){
//            result[n/2][n/2] = count++;
//        }
//        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

