




//给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充
//。
//
// 
// 
// 
// 
// 
//
// 示例 1： 
// 
// 
//输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O",
//"X","X"]]
//输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都
//会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
// 
//
// 示例 2： 
//
// 
//输入：board = [["X"]]
//输出：[["X"]]
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 200 
// board[i][j] 为 'X' 或 'O' 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 1107 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int dir[4][2] = {0,1,0,-1,1,0,-1,0};
    void dfs(vector<vector<char>> &board,int x, int y){
        board[x][y] = 'A';
        for (int i = 0; i < 4; ++i) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx>=board.size()||nextx<0||nexty>=board[0].size()|| nexty<0) continue;
            if (board[nextx][nexty]=='X'||board[nextx][nexty]=='A') continue;
            dfs(board,nextx,nexty);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int x = board.size();
        int y = board[0].size();
        for (int i = 0; i < x; ++i) {
            if (board[i][0]=='O')dfs(board,i,0);
            if (board[i][y-1]=='O') dfs(board,i,y-1);
        }
        for (int j = 0; j < y; ++j) {
            if (board[0][j]=='O') dfs(board,0,j);
            if (board[x-1][j]=='O') dfs(board,x-1,j);
        }
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (board[i][j]== 'O') board[i][j] = 'X';
                if (board[i][j]=='A') board[i][j] = 'O';

            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

