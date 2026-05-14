class MinStack {
public:
stack<int>st;
priority_queue<int,vector<int>,greater<int>>pq;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(pq.empty() || pq.top()>=val)pq.push(val);
    }
    
    void pop() {
        int front=st.top();
        st.pop();
        if(pq.top()==front)pq.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return pq.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */