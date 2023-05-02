// 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

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
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* node = head;
        while (node != NULL && node->next != NULL){
            if (node->next->val == val){
                ListNode* node1 = node->next;
                node->next = node->next->next;
                delete node1;
            }
            else{
                node = node->next;
            }
        }
        return head;
    }
};
