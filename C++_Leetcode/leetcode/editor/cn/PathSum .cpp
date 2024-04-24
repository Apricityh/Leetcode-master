




//给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和
// targetSum 。如果存在，返回 true ；否则，返回 false 。 
//
// 叶子节点 是指没有子节点的节点。 
//
// 
//
// 示例 1： 
// 
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//输出：true
//解释：等于目标和的根节点到叶节点路径如上图所示。
// 
//
// 示例 2： 
// 
// 
//输入：root = [1,2,3], targetSum = 5
//输出：false
//解释：树中存在两条根节点到叶子节点的路径：
//(1 --> 2): 和为 3
//(1 --> 3): 和为 4
//不存在 sum = 5 的根节点到叶子节点的路径。 
//
// 示例 3： 
//
// 
//输入：root = [], targetSum = 0
//输出：false
//解释：由于树是空的，所以不存在根节点到叶子节点的路径。
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [0, 5000] 内 
// -1000 <= Node.val <= 1000 
// -1000 <= targetSum <= 1000 
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1246 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

//Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode() : val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//};

class Solution {
public:
//    bool traversal(TreeNode* root,int count){
//        if (!root->left&&!root->right&&count==0){return true;}
//        if (!root->left&&!root->right) return false;
//        if (root->left){
//            count-= root->left->val;
//            if (traversal(root->left,count)) return true;
//            count+=root->left->val;
//        }  if (root->right){
//            count-= root->right->val;
//            if (traversal(root->right,count)) return true;
//            count+=root->right->val;
//        }
//        return false;
//    }
//    bool hasPathSum(TreeNode* root, int targetSum) {
//        return traversal(root,targetSum-root->val);
//    }
    bool ret = 0;
    int tar;
    void dfs(TreeNode* root, int sum){
        if (root== nullptr||ret)return;
        if (root->left== nullptr&&root->right== nullptr){
            sum+=root->val;
            if (sum==tar) ret=1;
            return;
        }
        dfs(root->left,sum+root->val);
        dfs(root->right,sum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum){
    tar = targetSum;
        dfs(root,0);
        return ret;
}
};
//leetcode submit region end(Prohibit modification and deletion)

