


//编写一个函数来查找字符串数组中的最长公共前缀。
//
// 如果不存在公共前缀，返回空字符串 ""。 
//
// 
//
// 示例 1： 
//
// 
//输入：strs = ["flower","flow","flight"]
//输出："fl"
// 
//
// 示例 2： 
//
// 
//输入：strs = ["dog","racecar","car"]
//输出：""
//解释：输入不存在公共前缀。 
//
// 
//
// 提示： 
//
// 
// 1 <= strs.length <= 200 
// 0 <= strs[i].length <= 200 
// strs[i] 仅由小写英文字母组成 
// 
//
// Related Topics 字符串 👍 2521 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        int i = -1;
        while (strs[0][++i])
            for (int j = 1; j < strs.size(); j++)
                if (strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            return strs[0].substr(0, i);


    }


};
//leetcode submit region end(Prohibit modification and deletion)

