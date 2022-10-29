


//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 每个右括号都有一个对应的相同类型的左括号。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "()[]{}"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：s = "(]"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// s 仅由括号 '()[]{}' 组成 
// 
//
// Related Topics 栈 字符串 👍 3576 👎 0


#include<bits/stdc++.h>
#include<stack>
#include<unordered_map>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        stack<char> C;
        unordered_map<char, char> Map = {
                {'}', '{'},
                {')', '('},
                {']', '['}
        };/***定义一个hashtable   以右括号来查找栈中是否有左括号  最先遇到的右括号一定先解决最近的左括号
不会出现 {（}）的情况
 ***/
 //key value
        int n = s.size();//length()/size() 都可以
        if (n % 2 == 1) {
            return false;    //若符号的个数是奇数则不匹配
        }
        for (char x: s) {    //遍历字符串的方式
            if (Map.count(x)) {    //  通过Key来确定栈里是否有左括号的存在，如果栈为空或者栈顶不为空则Push
                if (C.empty() || C.top() != Map[x]) {
                    return false;
                }
                else{   //有则消除   pop the string
                    C.pop();}}
            else{
                    C.push(x);   //插入左括号
                }


        }
        return C.empty();  //处理完只需要判断是否栈为空就行。

    }
};
//leetcode submit region end(Prohibit modification and deletion)

