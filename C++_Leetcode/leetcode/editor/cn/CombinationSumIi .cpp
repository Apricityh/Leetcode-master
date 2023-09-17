


//给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
// candidates 中的每个数字在每个组合中只能使用 一次 。 
//
// 注意：解集不能包含重复的组合。 
//
// 
//
// 示例 1: 
//
// 
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//] 
//
// 示例 2: 
//
// 
//输入: candidates = [2,5,2,1,2], target = 5,
//输出:
//[
//[1,2,2],
//[5]
//] 
//
// 
//
// 提示: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// Related Topics 数组 回溯 👍 1442 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backTracking(vector<int> &candidates, int index,int target, int sum, vector<bool> used) {
        if (sum>target){ return;}
        if (sum==target){
            result.push_back(path);
            return;}
        for (int i = index; i <candidates.size() ; ++i) {
            //层去重 i-1防止越界 ，  当前一个数字与后一个数字相等的时候，且前一个数字的used数组下标为false 没用的时候，那么代表着这个已经是在重复访问后面这个数了
            //类似于 1.1.2    for循环i=1时，层次遍历第二个数的时候
            if (i>0&&candidates[i-1]==candidates[i]&&used[i-1]==false){
                continue;
            }
            path.push_back(candidates[i]);
            used[i]=true;
            sum+=candidates[i];
            backTracking(candidates,i+1,target,sum,used);
            //回溯
            path.pop_back();
            sum-=candidates[i];
            used[i] = false;
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        result.clear();
        path.clear();
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backTracking(candidates,0,target,0,used);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

