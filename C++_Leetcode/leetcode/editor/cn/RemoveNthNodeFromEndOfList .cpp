


//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1], n = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2], n = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中结点的数目为 sz 
// 1 <= sz <= 30 
// 0 <= Node.val <= 100 
// 1 <= n <= sz 
// 
//
// 
//
// 进阶：你能尝试使用一趟扫描实现吗？ 
//
// Related Topics 链表 双指针 👍 2282 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)



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
    int GetLength(ListNode *head) {
       int len = 0;
       while(head){
           len++;
           head = head->next;
       }
       return len;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n) {
//        ListNode *prev = head;
//        ListNode *tail = head->next;
//        ListNode *pre = new ListNode(0,head);
//        if(head->next==nullptr&&n==1)
//            return {} ;
//
//        for (int i = 1; i < n; ++i) {
//                tail = tail->next;
//        }
//        while (tail->next!= nullptr) {
//            tail = tail->next;
//            head = head->next;
//            pre = pre->next;
//        }
//        pre->next = head->next;
//        delete head;
//        return prev;
        ListNode *dumm = new ListNode(0);
        dumm->next = head;
        ListNode *cur = dumm;
        int length = GetLength(head);
        for (int i = 1; i < length-n+1; ++i) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return dumm->next;  //虚拟节点很重要，可以防止删除头结点的情况
    }

};
//leetcode submit region end(Prohibit modification and deletion)

