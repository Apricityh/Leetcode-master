


//给你一个大小为 m x n 的二进制矩阵 grid 。
//
// 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都
//被 0（代表水）包围着。 
//
// 岛屿的面积是岛上值为 1 的单元格的数目。 
//
// 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。 
//
// 
//
// 示例 1： 
// 
// 
//输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,
//0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,
//0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
//输出：6
//解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[0,0,0,0,0,0,0,0]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 50 
// grid[i][j] 为 0 或 1 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 1060 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
//    int temp = 0;
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y,int &t) {


        for (int i = 0; i < 4; ++i) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nexty < 0 || nextx >= grid.size() || nexty >= grid[0].size()) { continue; }
            if (!visited[nextx][nexty] && grid[nextx][nexty] == 1) {
                t++;
                visited[nextx][nexty] = true;
                dfs(grid, visited, nextx, nexty,t);
            }
        }

    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxAre = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    visited[i][j] = true;
                    int temp = 1;
                    dfs(grid, visited, i, j,temp);
                    maxAre = max(maxAre, temp);
                }

            }
        }
        return maxAre;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

