




//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2: 
//
// 
//输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// k 的取值范围是 [1, 数组中不相同的元素的个数] 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的 
// 
//
// 
//
// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。 
//
// Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 👍 1618 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    class MyCompare{
    public:
        bool operator()(const pair<int,int> &left,const pair<int,int> &right){
            return left.second>right.second;   //仿函数返回左边的大于右边的次数  首先返回大的数 按照从大到小的顺序排 优先级高的元素在队列顶部
            // 我们以pair<int, int>的second（也就是元素出现的次数）来进行比较。
            // 所以，当lhs.second大于rhs.second时，意味着lhs的出现次数更多，应该拥有较高的优先级，它应该排在rhs的前面，即在堆中处于较小的位置。
            // 在小顶堆中，堆顶元素拥有最高的优先级，是所有元素中最小的元素。而随着向下移动堆的层级，元素的优先级逐渐减小，也就是说，
            // 堆顶元素的优先级最高，处于较小的位置，而堆底的元素优先级较低，处于较大的位置。一点一点加，最大的就跑到最下面去了
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map[nums[i]]++;//统计出现的次数
        }
        //构建一个小顶堆
        priority_queue<std::pair<int,int>,std::vector<pair<int,int>>,MyCompare> pri_que;
        for (auto it = map.begin();it!=map.end();it++) {
            pri_que.push(*it);
            if (pri_que.size()>k){
                pri_que.pop();
            }

        }
        vector<int> result;
        for (int i = k-1; i >=0 ; --i) {
            result.push_back(pri_que.top().first);
            pri_que.pop();
        }
        reverse(result.begin(),result.end());
        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

