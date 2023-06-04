// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。


// cpp
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* _dummyNode = new ListNode(0);
        _dummyNode->next = head;
        ListNode* left = _dummyNode;
        ListNode* right = _dummyNode;
        while (n--){
            right = right->next;
        }
        while (right->next != NULL){
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
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
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummyNode = ListNode(0, head)
        left = dummyNode
        right = dummyNode
        for _ in range(n):
            right = right.next
        while (right.next != None):
            left = left.next
            right = right.next
        left.next = left.next.next
        return dummyNode.next
