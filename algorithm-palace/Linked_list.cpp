// 203.移除链表元素
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


// 707.设计链表
// 你可以选择使用单链表或者双链表，设计并实现自己的链表。
// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

// 实现 MyLinkedList 类：
// MyLinkedList() 初始化 MyLinkedList 对象。
// int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
// void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
// void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
// void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
// void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。

class MyLinkedList {
public:

    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(nullptr){};
    };

    MyLinkedList() {
        _size = 0;
        _dummyHead = new ListNode(0);
    }
    
    int get(int index) {
        if (index < 0 || index >= _size){
            return -1;
        }

        ListNode* cur = _dummyHead;
        while (index--){
            cur = cur->next;
        }
        return cur->next->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = _dummyHead->next;
        _dummyHead->next = node;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (cur->next != NULL){
            cur = cur->next;
        }
        cur->next = node;
        node->next = NULL;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size){
            return;
        }

        ListNode* node = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (index--){
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size){
            return;
        }

        ListNode* cur = _dummyHead;
        while (index--){
            cur = cur->next;
        }
        ListNode* node = cur->next;
        cur->next = cur->next->next;
        delete node;
        _size--;
    }

private:
    int _size;
    ListNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


// 206.翻转链表
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


// 24.两两互换
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


// 19.删除链表的倒数第N个节点
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


// 链表相交
// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

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


// 142.环形链表II
// 给定一个链表的头节点 head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
// 不允许修改 链表。

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow){
                ListNode* node = head;
                while (node != fast){
                    fast = fast->next;
                    node = node->next;
                }
                return node;
            }
        }
        return NULL;
    }
};
