class MinStack {
private:
    std::stack<int> st;
    std::stack<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        // Push to minStack if empty OR if val is <= current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        // If popped value is the current minimum, pop from minStack as well
        if (st.top() == minStack.top()) {
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};