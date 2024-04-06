




//给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。 
//
// 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。 
//
// 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。 
//
// 
//
// 示例 1： 
// 
// 
//输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
//输出：3
//解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
// 
//
// 示例 2： 
// 
// 
//输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
//输出：0
//解释：所有 1 都在边界上或可以到达边界。
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 500 
// grid[i][j] 的值为 0 或 1 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 266 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int count = 0;
    int dir[4][2] = {0,-1,0,1,1,0,-1,0};
    void dfs(vector<vector<int>>& grid,int x ,int y){
        grid[x][y]=0;
        count++;//后续最后重新计算，和visited数组相似。
        for (int i = 0; i < 4; ++i) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx>=grid.size()||nextx<0||nexty>=grid[0].size()||nexty<0){
                continue;
            }
            if (grid[nextx][nexty]==0){ continue;}
            dfs(grid,nextx,nexty);
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
//从靠边两侧到中间遍历，为了将gird[x][y]==1的置零
        for (int i = 0; i < x; ++i) {
            if (grid[i][0] == 1) { dfs(grid, i, 0); }
            if (grid[i][y - 1] == 1) { dfs(grid, i, y - 1); }
        }
        //从上下到中间遍历，置零。
        for (int j = 0; j < y; ++j) {
            if (grid[0][j] == 1) { dfs(grid, 0, j); }
            if (grid[x - 1][j] == 1) { dfs(grid, x - 1, j); }
        }
        count = 0;//重新开始计算
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                if (grid[i][j] == 1) { dfs(grid, i, j); }
            }
        }
    return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

