class MyStack {
public:    
    queue<int> q;
    
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        
        int n = q.size() - 1;
        while(n > 0){
            q.push(pop());
            n--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = top(); q.pop();
        
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
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