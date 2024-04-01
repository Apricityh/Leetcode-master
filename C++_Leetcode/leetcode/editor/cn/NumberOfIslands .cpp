




//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 2459 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int dir[4][2] = {0,1,0,-1,-1,0,1,0};
    void dfs(vector<vector<char>>& grid,vector<vector<bool>> &visited,int x,int y){
        if (visited[x][y]||grid[x][y]=='0'){
            return;
        }
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nextx = x+dir[i][0];
            int nexty = y+dir[i][1];
            if (nextx<0||nexty<0||nextx>=grid.size()||nexty>=grid[0].size()){ continue;}
            dfs(grid,visited,nextx,nexty);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j]&&grid[i][j]=='1'){
                    result++;
                    dfs(grid,visited,i,j);
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

