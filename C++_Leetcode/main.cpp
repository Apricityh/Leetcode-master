#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int _val):val(_val),next(nullptr){}
    ListNode(int _val,ListNode*node):val(_val),next(node){}
};
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
    
}
;