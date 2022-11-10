


//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
// 
//
// 示例 2： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 100] 内 
// 0 <= Node.val <= 100 
// 
//
<<<<<<< HEAD
// Related Topics 递归 链表 👍 1620 👎 0
=======
// Related Topics 递归 链表 👍 1622 👎 0
>>>>>>> dev


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
<<<<<<< HEAD
        ListNode *prev = new ListNode(0);
        prev->next= head;
        ListNode *pre = prev;
        while(pre->next!=nullptr && prev->next->next!= nullptr){
            ListNode *n1 = pre->next;
            ListNode *n2 = pre->next->next;
            pre->next = n2;
            n1->next = n2->next;
            n2->next = n1;
            pre = n1;
        }
        return prev->next;
=======
//The second solution 递归
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *two = head->next;
        head->next = swapPairs(two->next);
        two->next = head;
        return two;

>>>>>>> dev
    }
};
//leetcode submit region end(Prohibit modification and deletion)

