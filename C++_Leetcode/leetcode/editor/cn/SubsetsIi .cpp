


//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
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
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics 位运算 数组 回溯 👍 1151 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int> &nums,int index,vector<bool> used){

        for (int i = index; i <nums.size() ; ++i) {
            //依旧是去重
            if (i>0&&nums[i]==nums[i-1]&&used[i-1]==false){
                continue;
            }
            path.push_back(nums[i]);
            result.push_back(path);
            used[i]=true;
            backTracking(nums,i+1,used);
            used[i]=false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        result.clear();
        path.clear();
        result.push_back(path);
        vector<bool> used(nums.size(), false);
        //排序
        sort(nums.begin(),nums.end());
        backTracking(nums,0,used);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

