


//给定一个非空的字符串
// s ，检查是否可以通过由它的一个子串重复多次构成。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abab"
//输出: true
//解释: 可由子串 "ab" 重复两次构成。
// 
//
// 示例 2: 
//
// 
//输入: s = "aba"
//输出: false
// 
//
// 示例 3: 
//
// 
//输入: s = "abcabcabcabc"
//输出: true
//解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
// 
//
// 
//
// 提示： 
//
// 
// 
//
// 
// 1 <= s.length <= 10⁴ 
// s 由小写英文字母组成 
// 
//
// Related Topics 字符串 字符串匹配 👍 997 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t = t.substr(1,t.size()-2);//substr(pos,count) count是字符数 pos起始位置
        if (t.find(s)!= string::npos){//如果查找成功，返回按照查找规则找到的第一个字符或者子串的位置；如果查找失败，返回string::npos,即-1（当然打印出的结果不是-1，而是一个很大的数值，那是因为它是无符号的）
            return true;
        }
        return false;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

