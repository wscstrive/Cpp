// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* _dummyNode = new ListNode(0);
        _dummyNode->next = head;
        ListNode* cur = _dummyNode;
        while (cur->next != NULL && cur->next->next != NULL){
            ListNode* node = cur->next;
            ListNode* temp = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = node;
            cur->next->next->next = temp;

            cur = cur->next->next;
        }
        return _dummyNode->next;
    }
};

// python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummyNode = ListNode(0, head)
        cur = dummyNode
        while cur.next and cur.next.next:
            node1 = cur.next
            node2 = cur.next.next.next
            cur.next = cur.next.next
            cur.next.next = node1
            cur.next.next.next = node2
            cur = cur.next.next
        return dummyNode.next
        
