




//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并
//返回这颗 二叉树 。 
//
// 
//
// 示例 1: 
// 
// 
//输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//输出：[3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//输入：inorder = [-1], postorder = [-1]
//输出：[-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= inorder.length <= 3000 
// postorder.length == inorder.length 
// -3000 <= inorder[i], postorder[i] <= 3000 
// inorder 和 postorder 都由 不同 的值组成 
// postorder 中每一个值都在 inorder 中 
// inorder 保证是树的中序遍历 
// postorder 保证是树的后序遍历 
// 
//
// Related Topics 树 数组 哈希表 分治 二叉树 👍 1094 👎 0


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
    TreeNode* traversal(vector<int>&inorder,vector<int> &postorder){
        if (postorder.size()==0)return nullptr;
        int nodeValue= postorder[postorder.size()-1];
        TreeNode *node = new TreeNode(nodeValue);
        if (postorder.size()==1){return node;}
        //重新定义后续数组的长度
        postorder.resize(postorder.size()-1);
        //找到后续最后一个数在中序数组里面的位置，便于分割中序数组
        int nodeIndex;
        for ( nodeIndex = 0; nodeIndex <inorder.size() ; ++nodeIndex) {
            if (inorder[nodeIndex]==nodeValue) break;
        }
        //分割中序数组
        vector<int> leftInorder(inorder.begin(),inorder.begin()+nodeIndex);
        vector<int> rightInorder(inorder.begin()+nodeIndex+1,inorder.end());

        //分割后续数组
        vector<int> leftPostorder(postorder.begin(),postorder.begin()+nodeIndex);
        vector<int> rightPostorder(postorder.begin()+nodeIndex,postorder.end());
        //递归
        node->left = traversal(leftInorder,leftPostorder);
        node->right = traversal(rightInorder,rightPostorder);
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()==0||postorder.size()==0){
            return nullptr;
        }
        return traversal(inorder,postorder);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

