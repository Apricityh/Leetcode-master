




//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 2622 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    const string map[10]={
            {""},
            {""},
            {"abc"},
            {"def"},
            {"ghi"},
            {"jkl"},
            {"mno"},
            {"pqrs"},
            {"tuv"},
            {"wxyz"}
    };
    vector<string> result;
    string s;
public:
    void backTracking(string &digits,int index){
        if (s.size()==digits.size()){
            result.push_back(s);
            return;
        }
        int num = digits[index]-'0';//因为是计算AsCII码
        string temp = map[num];
        for (int i = 0; i < temp.size(); ++i) {
            s.push_back(temp[i]);
            backTracking(digits,index+1);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if (digits.size()==0){
            return result;
        }
        //index是去取第几个数字的，便于在map里面挑选对应的字符串
        backTracking(digits,0);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

