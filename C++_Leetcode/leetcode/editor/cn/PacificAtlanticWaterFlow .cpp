


//有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。 
//
// 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上
//单元格 高于海平面的高度 。 
//
// 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。 
//
// 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可
//流向大西洋 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
//输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// 
//
// 示例 2： 
//
// 
//输入: heights = [[2,1],[1,2]]
//输出: [[0,0],[0,1],[1,0],[1,1]]
// 
//
// 
//
// 提示： 
//
// 
// m == heights.length 
// n == heights[r].length 
// 1 <= m, n <= 200 
// 0 <= heights[r][c] <= 10⁵ 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 数组 矩阵 👍 682 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int x, int y) {
        if (visited[x][y]) return;
        visited[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if (nextx < 0 || nexty < 0 || nextx >= heights.size() || nexty >= heights[0].size())continue;
            if (heights[x][y] > heights[nextx][nexty]) continue; //很重要
            dfs(heights, visited, nextx, nexty);
        }
        return;
    }

//    bool compete(vector<vector<int>>& heights,int x, int y){
//        vector<vector<bool>> visited(heights.size(),vector<bool>(heights[0].size(),false));
//        dfs(heights,visited,x,y);//遍历完之后看一下四周是否为true;
//        bool leftAndHead = false;
//        bool rightAndTail = false;
//        for (int i = 0; i < heights[0].size(); ++i) {
//            if (visited[0][i]){
//                leftAndHead = true;
//            }
//        }
//        for (int i = 0; i < heights.size(); ++i) {
//            if (visited[i][0])
//                leftAndHead = true;
//        }
//        for (int i = 0; i < heights[0].size(); ++i) {
//            if (visited[heights.size()-1][i])
//                rightAndTail = true;
//        }
//        for (int i = 0; i < heights.size(); ++i) {
//            if (visited[i][heights[0].size()-1])
//                rightAndTail = true;
//        }
//        return leftAndHead&&rightAndTail;
//    }
//    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//        vector<vector<int>> result;
//
//        for (int i = 0; i <heights.size() ; ++i) {
//            for (int j = 0; j < heights[0].size(); ++j) {
//                if (compete(heights,i,j))result.push_back({i,j});
//            }
//        }
//        return result;
//    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        vector<vector<int>> result;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> visitedLeftAndHead(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> visitedRightAndTail(heights.size(), vector<bool>(heights[0].size(), false));
        for (int i = 0; i < n; ++i) {
            dfs(heights, visitedLeftAndHead, i, 0);
            dfs(heights, visitedRightAndTail, i, m - 1);
        }
        for (int j = 0; j < m; ++j) {
            dfs(heights, visitedLeftAndHead, 0, j);
            dfs(heights, visitedRightAndTail, n - 1, j);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visitedRightAndTail[i][j] && visitedLeftAndHead[i][j]) result.push_back({i, j});
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

