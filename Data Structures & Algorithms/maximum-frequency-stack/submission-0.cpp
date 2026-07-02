class FreqStack {
    priority_queue<vector<int>> pq;
    map<int,int> cnt;
    vector<int> nums;
public:
    FreqStack() {

    }
    
    void push(int val) {
        nums.push_back(val);
        pq.push({++cnt[val],(int)nums.size(),val});
    }
    
    int pop() {
        int maxFreq = pq.top()[0], res = pq.top()[2]; pq.pop();
        for (int i=nums.size()-1; i>=0; i--) {
            if (maxFreq == cnt[nums[i]]) {
                cnt[res]--;
                nums.erase(nums.begin()+i);
                return res;
            }
        }
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
 