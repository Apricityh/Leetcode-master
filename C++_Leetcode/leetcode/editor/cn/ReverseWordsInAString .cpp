


//给你一个字符串 s ，请你反转字符串中 单词 的顺序。
//
// 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。 
//
// 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。 
//
// 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "the sky is blue"
//输出："blue is sky the"
// 
//
// 示例 2： 
//
// 
//输入：s = "  hello world  "
//输出："world hello"
//解释：反转后的字符串中不能存在前导空格和尾随空格。
// 
//
// 示例 3： 
//
// 
//输入：s = "a good   example"
//输出："example good a"
//解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// s 包含英文大小写字母、数字和空格 ' ' 
// s 中 至少存在一个 单词 
// 
//
// 
// 
//
// 
//
// 进阶：如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 O(1) 额外空间复杂度的 原地 解法。 
//
// Related Topics 双指针 字符串 👍 915 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //整体思路：首先是将s里面的数据处理成首尾都没有空格，再处理中间部分，只保留一个空格。用双指针，之后再对每一个单词进行反转。
//    void reverse(string &s, int start, int end) {//反转每个单词的顺序
//        while (start < end) {
//            swap(s[start++], s[end--]);
//        }
//    }
//
//    void moveSpace(string &s) {
//        int start = 0;
//        for (int i = 0; i < s.size(); i++) {
//            if (s[i] != ' ') {//去除所有空格，之后需要添加，首先给出一个条件是保证不是第一个字符
//                if (start != 0) {
//                    s[start++] = ' '; }
//                while (i < s.size() && s[i] != ' ') {
//                    s[start++] = s[i++];
//                }
//            }
//        }
//        s.resize(start);
//    }
//
//    string reverseWords(string s) {
//        moveSpace(s);
//        reverse(s, 0, s.size() - 1);
//        int start = 0;
//        for (int i = 0; i <= s.size(); ++i) {//反转每一个小部分
//            if (i == s.size() || s[i] == ' ') {
//                reverse(s, start, i - 1);
//                start = i + 1;//这儿不能放到外面去
//            }
//
//
//        }
//        return s;

    void reverse(string &s,int left,int right){
       while(left<right){
           swap(s[left++],s[right--]);
       }
    }
    void moveSpace(string &s){
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]!=' '){
                if (start!=0){
                    s[start++] = ' ';
                }
                while(s[i]!=' '&&i<s.size()){
                    s[start++]=s[i++];
                }
            }
        }
        s.resize(start);
    }


        string reverseWords(string s) {
            moveSpace(s);
            reverse(s, 0, s.size() - 1);
            int start = 0;
            for (int i = 0; i <= s.size(); ++i) {//反转每一个小部分
                if (i == s.size() || s[i] == ' ') {
                    reverse(s, start, i - 1);
                    start = i + 1;//这儿不能放到外面去
                }


            }
            return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

