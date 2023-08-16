


//给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
//
// 
//
// 示例1： 
//
// 
//
// 
//输入: root = [1,3,2,5,3,null,9]
//输出: [1,3,9]
// 
//
// 示例2： 
//
// 
//输入: root = [1,2,3]
//输出: [1,3]
// 
//
// 
//
// 提示： 
//
// 
// 二叉树的节点个数的范围是 [0,10⁴] 
// 
// -2³¹ <= Node.val <= 2³¹ - 1 
// 
//
// 
//
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 326 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
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
    vector<int> largestValues(TreeNode *root) {
        queue<TreeNode *> que;
        if (root) { que.push(root); }
        vector<int> result;
        while (!que.empty()) {
            int size = que.size();
            int num = INT32_MIN;
            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                num = node->val > num ? node->val : num;
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            result.push_back(num);

        }
        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

