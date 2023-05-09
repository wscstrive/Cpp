// 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

// 实现 MyStack 类：

// void push(int x) 将元素 x 压入栈顶。
// int pop() 移除并返回栈顶元素。
// int top() 返回栈顶元素。
// boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

class MyStack {
public:
    queue<char> queue;
    MyStack() {

    }
    
    void push(int x) {
        int n = queue.size();
        queue.push(x);
        for (int i = 0; i < n; i++){
            queue.push(queue.front());
            queue.pop();
        }
    }
    
    int pop() {
        if (!queue.empty()){
            int x = queue.front();
            queue.pop();
            return x;
        }
        return 0;
    }
    
    int top() {
        if (!queue.empty()){
            return queue.front();
        }
        return 0;
    }
    
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
