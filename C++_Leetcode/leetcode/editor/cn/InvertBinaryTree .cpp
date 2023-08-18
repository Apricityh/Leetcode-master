




//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [4,2,7,1,3,6,9]
//输出：[4,7,2,9,6,3,1]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：root = [2,1,3]
//输出：[2,3,1]
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目范围在 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1654 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

 //Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
//        if (root== nullptr){return root;}
//        swap(root->left,root->right);
//        invertTree(root->left);
//        invertTree(root->right);//需要考虑的是为什么中序遍历是不可以的，因为中序遍历在处理左边完毕后，换到了右边，但是右边的从开始到结尾都没等到处理。
//        return root;
//层序遍历
        queue<TreeNode*> que;
        if(root){que.push(root);}
        while(!que.empty()){
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left){que.push(node->left);}
                if (node->right){que.push(node->right);}
                swap(node->left,node->right);

            }
        }
        return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

