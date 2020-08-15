class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> primary;
    stack<int> sec;
    
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        while(!sec.empty())
        {
            primary.push(sec.top());
            sec.pop();
        }
        
        primary.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        while(!primary.empty())
        {
            sec.push(primary.top());
            primary.pop();
        }
        
        int res = sec.top();
        sec.pop();
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        
        while(!primary.empty())
        {
            sec.push(primary.top());
            primary.pop();
        }
        
        int res = sec.top();
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (primary.empty() && sec.empty());
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