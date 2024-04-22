




//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
// 
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
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
// 链表中节点的数目在范围 [0, 5 * 10⁴] 内 
// -10⁵ <= Node.val <= 10⁵ 
// 
//
// 
//
// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
//
// Related Topics 链表 双指针 分治 排序 归并排序 👍 2291 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

        ListNode* sortList(ListNode* head) {
            if (head == nullptr) {
                return nullptr;
            }
            vector<int> List;
            while (head) {
                List.push_back(head->val);
                head = head->next;
            }
            sort(List.begin(), List.end());
            ListNode *curry = new ListNode();
            ListNode *node = new ListNode(List[0]);
            curry->next = node;
            for (int i = 1; i < List.size(); i++) {

                ListNode *temp = new ListNode(List[i]);
                node->next = temp;
                node = temp;
            }
            return curry->next;
        }

};
//leetcode submit region end(Prohibit modification and deletion)

