




//小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为
// root 。 
//
// 除了
// root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的
//房子在同一天晚上被打劫 ，房屋将自动报警。 
//
// 给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入: root = [3,2,3,null,3,null,1]
//输出: 7 
//解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7 
//
// 示例 2: 
//
// 
//
// 
//输入: root = [3,4,5,1,3,null,1]
//输出: 9
//解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
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
// 树的节点数在 [1, 10⁴] 范围内 
// 0 <= Node.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 动态规划 二叉树 👍 1966 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

//Definition for a binary tree node.
//  struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };

class Solution {
public:
    unordered_map<TreeNode*,int> map;
    int rob(TreeNode* root) {
//        if (root == NULL) return 0;
//        if (root->left == NULL && root->right == NULL) return root->val;
//        // 偷父节点
//        int val1 = root->val;
//        if (root->left) val1 += rob(root->left->left) + rob(root->left->right); // 跳过root->left，相当于不考虑左孩子了
//        if (root->right) val1 += rob(root->right->left) + rob(root->right->right); // 跳过root->right，相当于不考虑右孩子了
//        // 不偷父节点
//        int val2 = rob(root->left) + rob(root->right); // 考虑root的左右孩子
//        return max(val1, val2);
        if (root==nullptr)return 0;
        if (root->left== nullptr&&root->right== nullptr){
            return root->val;
        }
        if (map[root]) return map[root];
        int val1 = root->val;
        if (root->left)  val1+=  rob(root->left->left)+ rob(root->left->right);
        if (root->right) val1+=  rob(root->right->left)+ rob(root->right->right);
        int val2 = rob(root->left)+ rob(root->right);
        int result = max(val1,val2);
        map[root] = result;
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

