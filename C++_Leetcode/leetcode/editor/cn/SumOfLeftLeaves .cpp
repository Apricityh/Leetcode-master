




//给定二叉树的根节点 root ，返回所有左叶子之和。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: root = [3,9,20,null,null,15,7] 
//输出: 24 
//解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
// 
//
// 示例 2: 
//
// 
//输入: root = [1]
//输出: 0
// 
//
// 
//
// 提示: 
//
// 
// 节点数在 [1, 1000] 范围内 
// -1000 <= Node.val <= 1000 
// 
//
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 648 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

////  Definition for a binary tree node.
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
    //按照左右中的方式进行遍历
    int sumOfLeftLeaves(TreeNode* root) {
        //递归出口
        if (root== nullptr)return 0;
        if (root->left== nullptr&&root->right== nullptr){return 0;}
        int leftValue = sumOfLeftLeaves(root->left);//左孩子的最左侧结点
        if (root->left!= nullptr&&root->left->left== nullptr&&root->left->right== nullptr){
            leftValue = root->left->val;
        }
        int rightValue = sumOfLeftLeaves(root->right);
        int sum = rightValue + leftValue;
        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

