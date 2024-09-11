class MinStack {
    
public:
    stack<int> ST;
    stack<int> minST;
    MinStack() {}
    
    void push(int val) {
        ST.push(val);
        if( minST.empty() || ST.top()<=minST.top()){
            minST.push(val);
        }
    }
    
    void pop() {
        if(ST.top()==minST.top()){
            minST.pop();
        }
        ST.pop();
    }
    
    int top() {
      return ST.top();
    }
    
    int getMin() {
       return minST.top();
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