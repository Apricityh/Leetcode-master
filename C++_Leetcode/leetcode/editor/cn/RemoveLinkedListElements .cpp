


//给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,6,3,4,5,6], val = 6
//输出：[1,2,3,4,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [], val = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [7,7,7,7], val = 7
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 列表中的节点数目在范围 [0, 10⁴] 内 
// 1 <= Node.val <= 50 
// 0 <= val <= 50 
// 
//
// Related Topics 递归 链表 👍 1264 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.

// */
//struct ListNode {
//    int val;
//    ListNode *next;
//
//    ListNode() : val(0), next(nullptr) {}
//
//    ListNode(int x) : val(x), next(nullptr) {}
//
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
//        if (head == nullptr) {
//            return head;
//        }
//        ListNode *pre = new ListNode(0);
//        pre->next = head;
//        ListNode *cur = pre;
//        while (cur->next != nullptr) {
//            if (cur->next->val == val) {
//                ListNode *temp = cur->next;
//                cur->next = cur->next->next;
//                delete temp;
//            } else {
//                cur = cur->next;
//            }
//
//        }
//        return pre->next;
        if(head== nullptr){
            return nullptr;
        }
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* cur = pre;
        while(cur->next){
            if (cur->next->val==val){
                ListNode * temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }else{
                cur = cur->next;
            }

        }
        return pre->next;











//        if (head == nullptr) {
//            return head;
//        }
//        ListNode *pre = new ListNode(0);
//        pre->next = head;
//        ListNode *cur = pre;
//        while (cur->next != nullptr) {
//            if (cur->next->val == val) {
//                ListNode *node = cur->next;
//                cur->next = cur->next->next;
//                delete node;
//            }else{
//            cur = cur->next;}
//        }
//        return pre->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

