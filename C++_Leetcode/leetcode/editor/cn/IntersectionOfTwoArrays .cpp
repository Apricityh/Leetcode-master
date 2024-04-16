


//给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,2,2,1], nums2 = [2,2]
//输出：[2]
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出：[9,4]
//解释：[4,9] 也是可通过的
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums1.length, nums2.length <= 1000 
// 0 <= nums1[i], nums2[i] <= 1000 
// 
//
// Related Topics 数组 哈希表 双指针 二分查找 排序 👍 788 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
//        //纯hashset方法，无序，去重，查找快  o(logn)
//    unordered_set<int> result;
//    unordered_set<int> num(nums1.begin(),nums1.end());
//    for(int i:nums2){
//        if (num.find(i)!= num.end()){
//            result.insert(i);
//        }
//    }
//    return vector<int>(result.begin(),result.end()) ;
//数组
//        unordered_set<int> result;
//        int arry[1001] = {0};//数组初始化
//        for (int num: nums1) {
//            arry[num] = 1;
//        }
//        for (int num: nums2) {
//            if (arry[num] == 1) {
//                result.insert(num);//有了就不会插进去了
//            }
//
//        }
//        return vector<int>(result.begin(), result.end());
//    }
//    //std::unordered_set的底层实现是哈希表， 使用unordered_set 读写效率是最高的，
//    // 并不需要对数据进行排序，而且还不要让数据重复，所以选择unordered_set。
        unordered_set<int> set(nums1.begin(),nums1.end());
        unordered_set<int>  res;

        for (int i = 0; i < nums2.size(); ++i) {
            if (set.count(nums2[i])) {
                res.insert(nums2[i]);
            }
        }
        return vector<int>(res.begin(),res.end());

    }
};
//leetcode submit region end(Prohibit modification and deletion)

