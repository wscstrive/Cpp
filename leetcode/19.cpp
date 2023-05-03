// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

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
