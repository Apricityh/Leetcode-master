


//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [100,4,200,1,3,2]
//输出：4
//解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。 
//
// 示例 2： 
//
// 
//输入：nums = [0,3,7,2,5,8,4,6,0,1]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 10⁵ 
// -10⁹ <= nums[i] <= 10⁹ 
// 
//
// Related Topics 并查集 数组 哈希表 👍 2027 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set;
        for (int &num: nums) {
            set.insert(num);
        }
        int longestNums = 0;
        for (const int &i: set) {
            if (!set.count(i - 1)) {
                int currentLens = 1;
                int currentNum = i;
                while (set.count( currentNum+1)) {
                    currentLens += 1;
                    currentNum +=1;
                }
                longestNums = max(longestNums, currentLens);
            }

        }
        return longestNums;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

