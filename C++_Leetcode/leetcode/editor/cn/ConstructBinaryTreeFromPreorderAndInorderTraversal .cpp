




//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并
//返回其根节点。 
//
// 
//
// 示例 1: 
// 
// 
//输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//输出: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入: preorder = [-1], inorder = [-1]
//输出: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均 无重复 元素 
// inorder 均出现在 preorder 
// preorder 保证 为二叉树的前序遍历序列 
// inorder 保证 为二叉树的中序遍历序列 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 2068 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

//Definition for a binary tree node.
//struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };

class Solution {
public:
    TreeNode* traversal(vector<int> &preorder,vector<int>& inorder){
        if (preorder.size()==0){
            return nullptr;
        }
        //找到根节点
        int nodeValue = preorder[0];
        TreeNode *root = new TreeNode(nodeValue);
        if (preorder.size()==1){
            return root;
        }
        //找到中序的根节点所在位置
        int nodeIndex;
        for (nodeIndex = 0; nodeIndex < inorder.size(); ++nodeIndex) {
            if (inorder[nodeIndex]==nodeValue){
                break;
            }
        }
        //更新中序
        vector<int> leftInorder(inorder.begin(),inorder.begin()+nodeIndex);
        vector<int> rightInorder(inorder.begin()+nodeIndex+1,inorder.end());
        //更新先序
        vector<int> leftPreorder(preorder.begin()+1,preorder.begin()+1+nodeIndex);
        vector<int> rightPreoder(preorder.begin()+1+nodeIndex,preorder.end());

        root->left = traversal(leftPreorder,leftInorder);
        root->right = traversal(rightPreoder,rightInorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0|| inorder.size()==0){
            return nullptr;
        }
        return traversal(preorder,inorder);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

