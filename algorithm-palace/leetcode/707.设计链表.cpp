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
        ListNode(int val):val(val),next(nullptr) {};
    };

    MyLinkedList() {
        _size = 0;
        _dummyHead = new ListNode(0);
    }
    
    int get(int index) {
        if (index < 0 || index >= _size) {
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

// python
class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class MyLinkedList:

    def __init__(self):
        self.size = 0
        self.dummyNode = ListNode()

    def get(self, index: int) -> int:
        if index < 0 or index >= self.size:
            return -1
        node = self.dummyNode
        for _ in range(index):
            node = node.next
        return node.next.val

    def addAtHead(self, val: int) -> None:
        self.dummyNode.next = ListNode(val, self.dummyNode.next)
        self.size += 1

    def addAtTail(self, val: int) -> None:
        node = self.dummyNode
        while node.next != None:
            node = node.next
        node.next = ListNode(val, None)
        self.size += 1
        
    def addAtIndex(self, index: int, val: int) -> None:
        if index > self.size:
            return
        node = self.dummyNode
        for _ in range(index):
            node = node.next
        node.next = ListNode(val, node.next)
        self.size += 1

    def deleteAtIndex(self, index: int) -> None:
        if index >= self.size:
            return
        node = self.dummyNode
        for _ in range(index):
            node = node.next
        node.next = node.next.next
        self.size -= 1



# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
