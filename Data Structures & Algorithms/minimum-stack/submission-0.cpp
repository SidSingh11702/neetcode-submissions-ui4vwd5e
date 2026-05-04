class MinStack {
    stack<int> st, minVals;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (minVals.empty() || val <= minVals.top()) minVals.push(val);
    }
    
    void pop() {
        if (minVals.top() == st.top()) minVals.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minVals.top();
    }
};
