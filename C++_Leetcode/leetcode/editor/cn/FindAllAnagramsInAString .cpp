




//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 
//
// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "cbaebabacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
// 
//
// 示例 2: 
//
// 
//输入: s = "abab", p = "ab"
//输出: [0,1,2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, p.length <= 3 * 10⁴ 
// s 和 p 仅包含小写字母 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 1408 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char ,int> need,windows;
        int left = 0;
        int right  = 0;
        int valid = 0;
        vector<int> result;
        for (char c:p) {
            need[c]++;
        }
        while(right<s.size()){
            char temp = s[right];
            right++;
            if (need.count(temp)){
                windows[temp]++;
                if (need[temp]==windows[temp]){
                    valid++;
                }
            }
            while((right-left)>=p.size()){
                if (valid==need.size()){
                    result.push_back(left);
                }
                char c = s[left];
                left++;
                if (need.count(c)){
                    if (windows[c]==need[c]){
                        valid--;
                    }
                    windows[c]--;
                }
            }
        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

