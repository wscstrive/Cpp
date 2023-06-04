// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
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

// cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = NULL;
        ListNode* cur = head;
        while (cur){
            ListNode* dummyNode = cur->next;
            cur->next = node;
            node = cur;
            cur = dummyNode;
        }
        return node;
    }
};

// python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummyNode = None
        cur = head
        while cur:
            node = cur.next
            cur.next = dummyNode
            dummyNode = cur
            cur = node
        return dummyNode
