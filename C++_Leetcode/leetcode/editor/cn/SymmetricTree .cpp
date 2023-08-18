




//给你一个二叉树的根节点 root ， 检查它是否轴对称。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,2,3,4,4,3]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,2,null,3,null,3]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [1, 1000] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？ 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 2507 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

 // Definition for a binary tree node.
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
    bool compare(TreeNode *left,TreeNode *right){
        if (left== nullptr&&right!= nullptr){return false;}
        else if (left&&right== nullptr) return false;
        else if (left== nullptr&&right == nullptr) return true;
        else if (left->val!=right->val)return false;
        bool outside = compare(left->left,right->right);//分为内层和外层数据
        bool inside = compare(left->right,right->left);
        return outside&&inside;
    }
    bool isSymmetric(TreeNode* root) {
        bool result = compare(root->left,root->right);
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

