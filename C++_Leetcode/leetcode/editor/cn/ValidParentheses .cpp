


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
        /***定义一个hashtable   以右括号来查找栈中是否有左括号  最先遇到的右括号一定先解决最近的左括号
不会出现 {（}）的情况
 ***/
        //key value
        int n = s.size();//length()/size() 都可以
        if (n % 2 !=0) {
            return false;    //若符号的个数是奇数则不匹配
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') C.push(')');
            else if (s[i] == '{') C.push('}');
            else if (s[i] == '[') C.push(']');
             else if(C.empty()||C.top()!=s[i]){
                return false;
            } else{
                C.pop();//右括号和左括号相等，弹出
            }
        }
        return C.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

