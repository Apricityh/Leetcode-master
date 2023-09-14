


//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
//
// 回文串 是正着读和反着读都一样的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：[["a"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 1624 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    vector<string> path;
    vector<vector<string>> result;
public:
    //判断会否为回文串，尤其注意其j-- 写错了一开始，不用等于  最后若是奇数不影响。
    bool isReverse(string &s, int begin, int end) {
        for (int i = begin, j = end; i < j; ++i, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    void backTracking(string &s, int index) {
        if (index >= s.size()) {
            // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            if (isReverse(s, index, i)) {
                string str = s.substr(index, i - index + 1);
                path.push_back(str);
            }
            else { continue; }
            backTracking(s, i + 1);
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        path.clear();
        result.clear();
        backTracking(s, 0);
        return result;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

