// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

// cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;
        int a = 0;
        int b = 0;
        while (node1 != NULL){
            node1 = node1->next;
            a++;
        }
        while (node2 != NULL){
            node2 = node2->next;
            b++;
        }
        node1 = headA;
        node2 = headB;
        if (b > a){
            swap (a, b);
            swap (node1, node2);
        }
        int gap = a - b;
        while (gap--){
            node1 = node1->next;
        }
        while (node1 != NULL){
            if (node1 == node2){
                return node1;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        return NULL;
    }
};

// python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        nodeA = headA
        disA = 0
        while nodeA:
            disA += 1
            nodeA = nodeA.next
        nodeB = headB
        disB = 0
        while nodeB:
            disB += 1
            nodeB = nodeB.next
        if disA < disB:
            disA, disB = disB, disA
            headA, headB = headB, headA
        dis = disA - disB
        nodeA = headA
        nodeB = headB
        for i in range(dis):
            nodeA = nodeA.next
        while nodeA:
            if nodeA == nodeB:
                return nodeA
            nodeA = nodeA.next
            nodeB = nodeB.next
        return None
