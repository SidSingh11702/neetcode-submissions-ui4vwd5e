class FreqStack {
    priority_queue<vector<int>> pq;
    map<int,int> cnt;
    int idx;
public:
    FreqStack() {
        idx = 0;
    }
    
    void push(int val) {
        pq.push({++cnt[val],++idx,val});
    }
    
    int pop() {
        int res = pq.top()[2]; pq.pop();
        cnt[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
