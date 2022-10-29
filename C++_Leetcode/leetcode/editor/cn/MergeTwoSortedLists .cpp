


//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
// 
//
// 示例 1： 
// 
// 
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
// 
//
// 示例 2： 
//
// 
//输入：l1 = [], l2 = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：l1 = [], l2 = [0]
//输出：[0]
// 
//
// 
//
// 提示： 
//
// 
// 两个链表的节点数目范围是 [0, 50] 
// -100 <= Node.val <= 100 
// l1 和 l2 均按 非递减顺序 排列 
// 
//
// Related Topics 递归 链表 👍 2758 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//        ListNode *L1 = list1;
//        ListNode *L2 = list2;
//        ListNode *list3;
//        list3 = new ListNode();
//        while (L1->next->val || L2->next->val)
//            if (L1->next == nullptr || L2->next == nullptr)
//                if (L1->next == nullptr)
//                    list3->next = new ListNode();
//                else {
//                    list3->next = L1->next;
//                }
//            else if (L1->val >= L2->val) {
//                list3->next = L2;
//            } else
//                list3->next = L1;
//
//        return list3;
       ListNode *tail = new ListNode(0);
       ListNode *head = tail;  //记录好头部
       while(l1!= nullptr&&l2!= nullptr) {
           if(l1->val > l2->val){
               tail->next = l2;
               l2 = l2->next;
           }
           else{
               tail->next = l1;
               l1 = l1->next;
           }
           tail = tail->next;
       }
       tail->next = l1==nullptr?l2:l1;
       return head->next;//head 是指向tail最开始的那片空间  而初始节点值为0
    }
};

//leetcode submit region end(Prohibit modification and deletion)

