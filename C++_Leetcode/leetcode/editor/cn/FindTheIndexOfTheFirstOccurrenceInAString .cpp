


//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//如果 needle 不是 haystack 的一部分，则返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：haystack = "sadbutsad", needle = "sad"
//输出：0
//解释："sad" 在下标 0 和 6 处匹配。
//第一个匹配项的下标是 0 ，所以返回 0 。
// 
//
// 示例 2： 
//
// 
//输入：haystack = "leetcode", needle = "leeto"
//输出：-1
//解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= haystack.length, needle.length <= 10⁴ 
// haystack 和 needle 仅由小写英文字符组成 
// 
//
// Related Topics 双指针 字符串 字符串匹配 👍 1914 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //首先是获取next数组
    void getNext(int *next,string s){
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); ++i) {
            while(j>0&&s[i]!=s[j]){
                j = next[j-1];//回退，不止一次
            }
            if (s[i]==s[j]){
                j++;
            }
            next[i] = j;
        }
   }
    int strStr(string haystack, string needle) {
//        //普通解法
//        for (int i = 0; i < haystack.size(); ++i) {
//            int k = i;
//            int j = 0;
//            while (k < haystack.size() && j < needle.size()) {
//                if (haystack[k++] != needle[j++]) {
//                    break;
//                }
//                if (j == needle.size()) {
//                    return i;
//                }
//            }
//        }
//        return -1;
        if (needle.size()==0){
            return 0;
        }
        int j = 0;
        int next[needle.size()];
        getNext(next,needle);
        for (int i = 0; i < haystack.size(); ++i) {
            while(j>0&&haystack[i]!=needle[j]){
                j = next[j-1];
            }
            if (haystack[i]==needle[j]){
                j++;//i++在循环体内部
            }
            if (j==needle.size()){
                return(i-needle.size()+1);
            }
        }
        return -1;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

