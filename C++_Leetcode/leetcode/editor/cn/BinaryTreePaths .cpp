


//给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
//
// 叶子节点 是指没有子节点的节点。 
//
// 示例 1： 
// 
// 
//输入：root = [1,2,3,null,5]
//输出：["1->2->5","1->3"]
// 
//
// 示例 2： 
//
// 
//输入：root = [1]
//输出：["1"]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// Related Topics 树 深度优先搜索 字符串 回溯 二叉树 👍 1020 👎 0


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
//    void Travsal(TreeNode *root, vector<int> &path, vector<string> &result) {
//        path.push_back(root->val);//将目前这个父节点加入path;
//        //递归终止条件
//        if (root->left== nullptr&&root->right== nullptr){
//            string spath;
//            for (int i = 0; i < path.size()-1; ++i) {
//                spath += to_string(path[i]);
//                spath +="->";
//            }
//            spath +=to_string(path[path.size()-1]);//因为上面的->缘故，最后不需->，最后叶子结点单独处理
//            result.push_back(spath);
//        }
//        if (root->left){
//            Travsal(root->left,path,result);
//            path.pop_back();//递归回溯在一起，一次递归一次回溯清空。
//        }
//        if(root->right){
//            Travsal(root->right,path,result);
//            path.pop_back();//回溯 清除路径
//        }
//    }
//    vector<string> binaryTreePaths(TreeNode *root) {
//        vector<int> path;
//        vector<string> result;
//        if (root == nullptr) { return result; }
//        Travsal(root, path, result);
//        return result;
//    }
        void trace(TreeNode *root,vector<int> &path,vector<string> &res){
        path.push_back(root->val);
        if (root->left== nullptr&&root->right==nullptr){
            string temp;
            for (int i = 0; i < path.size()-1; ++i) {
                temp+=to_string(path[i]);
                temp+="->";
            }
            temp+=to_string(path[path.size()-1]);
            res.push_back(temp);
        }
        if (root->left){
            trace(root->left,path,res);
            path.pop_back();
        }
        if (root->right){
            trace(root->right,path,res);
            path.pop_back();
        }


    }
        vector<string> binaryTreePaths(TreeNode *root){
            vector<int> path;
            vector<string> res;
            trace(root,path,res);
            return res;
        }
};
//leetcode submit region end(Prohibit modification and deletion)

