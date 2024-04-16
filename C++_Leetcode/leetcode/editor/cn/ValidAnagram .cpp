


//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//
// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "anagram", t = "nagaram"
//输出: true
// 
//
// 示例 2: 
//
// 
//输入: s = "rat", t = "car"
//输出: false 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, t.length <= 5 * 10⁴ 
// s 和 t 仅包含小写字母 
// 
//
// 
//
// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
//
// Related Topics 哈希表 字符串 排序 👍 800 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
        //直接排序
//        if (s.length()!=t.length()){
//            return false;
//        }
//        sort(s.begin(),s.end());
//        sort(t.begin(),t.end());
//        return s==t;
//hash表
        vector<int> res(26,0);
        for (int i = 0; i < s.size(); ++i) {
            res[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); ++i) {
            res[t[i]-'a']--;
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i]!=0){
                return false;
            }
        }
        return true;

    }
};
/*
 *在这段代码中，我们正在处理字符串中的字符，并且通过将字符减去字符 'a' 来计算它在 alp 数组中的索引位置。假设我们有一个字符串 s，其中包含小写字母 'a' 到 'z'，并且我们希望统计每个字母出现的次数。
 * 将字符 'a' 减去字符 'a' 将得到索引 0，将字符 'b' 减去字符 'a' 将得到索引 1，依此类推。
 * 通过这种方式，我们可以将每个字符映射到 alp 数组中的相应索引位置，从而统计每个字母出现的次数。
如果我们使用 alp[ch]++，则会直接使用字符 ch 作为索引，而不考虑其相对于字符 'a' 的偏移量。这将导致错误的索引，并且无法正确地统计字母出现的次数。
因此，在这种情况下，我们需要使用 alp[ch - 'a']++，以便根据字符 ch 相对于 'a' 的偏移量来确定正确的数组索引，并将对应的元素递增。
 */

//leetcode submit region end(Prohibit modification and deletion)

