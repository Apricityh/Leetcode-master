


//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
// 本题中，一棵高度平衡二叉树定义为： 
//
// 
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [3,9,20,null,null,15,7]
//输出：true
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,2,3,3,null,null,4,4]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：root = []
//输出：true
// 
//
// 
//
// 提示： 
//
// 
// 树中的节点数在范围 [0, 5000] 内 
// -10⁴ <= Node.val <= 10⁴ 
// 
//
// Related Topics 树 深度优先搜索 二叉树 👍 1394 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

//Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};

class Solution {
public:
    int getHight(TreeNode *root) {//需要用后序
        if (root == nullptr)
            return 0;
        int leftHight = getHight(root->left);
        if (leftHight == -1) {//左
            return -1;
        }
        int rightHight = getHight(root->right);
        if (rightHight == -1) {  //右
            return -1;
        }
        //中
        return abs(leftHight-rightHight)>1?-1: max(leftHight,rightHight)+1;//加1的原因是因为树结点的高度是从1开始计算的
        //这是为了保存当前节点的高度，左子树以及右子树的最高的+1
    }

    bool isBalanced(TreeNode *root) {
        return getHight(root)==-1? false: true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

