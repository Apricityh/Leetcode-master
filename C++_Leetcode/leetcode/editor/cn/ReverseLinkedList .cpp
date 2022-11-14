


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
// Related Topics 递归 链表 👍 2843 👎 0


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
    ListNode *reverseList(ListNode *head) {
  /**
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *curr = head;    //永远指定现链表的第一个位置
        ListNode *temp = head->next;//用于前面小块和后面元素的交换节点
        ListNode *tail = curr;    //用于方便的确定后面第一个元素的位置
        while (temp != nullptr) {
            tail->next = temp->next;  //  将前面指针放到后元素的后面
            temp->next = curr;   //与前面数据交换
            curr = temp;      //第一个元素交替
            temp = tail->next;   //temp已经变化
        }

        return curr;

**/
//递归
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;


    }




};
//leetcode submit region end(Prohibit modification and deletion)

