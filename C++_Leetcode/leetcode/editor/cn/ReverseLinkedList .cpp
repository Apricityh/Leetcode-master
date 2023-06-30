


//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
//
// 
// 
// 
// 
// 
//
// 示例 1： 
// 
// 
//输入：head = [1,2,3,4,5]
//输出：[5,4,3,2,1]
// 
//
// 示例 2： 
// 
// 
//输入：head = [1,2]
//输出：[2,1]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目范围是 [0, 5000] 
// -5000 <= Node.val <= 5000 
// 
//
// 
//
// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？ 
//
// Related Topics 递归 链表 👍 3193 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
//
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
//双指针法
class Solution {
public:
    ListNode *reverseList1(ListNode *head) {
        ListNode *temp;//用于保存断链后，后续的结点的暂存头结点
        ListNode *cur = head;//处理结点
        ListNode *pre = nullptr;//为了让其第一次初始化的时候头节点指向null;
        while (cur) {
            //先记录后面的结点
            temp = cur->next;
            //然后开始处理cur的指向
            cur->next = pre;
            //更新结点
            pre = cur;
            cur = temp;
        }
        //跳出条件是cur为空，那么上一次的cur就不为空，那么结点直接赋给pre了
        return pre;

    }

    ListNode *reverse(ListNode *pre, ListNode *cur) {
        if (cur == nullptr) {
            return pre;   //终止条件
        }
        ListNode *temp = cur->next; //迭代的第二个参数的保留
        cur->next = pre;  //更新结点
        return reverse(cur, temp);
    }

    ListNode *reverseList(ListNode *head) {
        return reverse(nullptr, head); //开始迭代
    }
};
//leetcode submit region end(Prohibit modification and deletion)

