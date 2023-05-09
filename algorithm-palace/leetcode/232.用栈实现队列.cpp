// 请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

// 实现 MyQueue 类：

// void push(int x) 将元素 x 推到队列的末尾
// int pop() 从队列的开头移除并返回元素
// int peek() 返回队列开头的元素
// boolean empty() 如果队列为空，返回 true ；否则，返回 false

class MyQueue {
public:

    stack<int> InSt;
    stack<int> OutSt;

    MyQueue() {

    }
    
    void push(int x) {
        InSt.push(x);
    }
    
    int pop() {
        if (OutSt.empty()){
            while (!InSt.empty()){
                OutSt.push(InSt.top());
                InSt.pop();
            }
        }

        int x = OutSt.top();
        OutSt.pop();
        return x;
    }
    
    int peek() {
        if (OutSt.empty()){
            while (!InSt.empty()){
                OutSt.push(InSt.top());
                InSt.pop();
            }
        }
        return OutSt.top();
    }
    
    bool empty() {
        if (InSt.empty() && OutSt.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
