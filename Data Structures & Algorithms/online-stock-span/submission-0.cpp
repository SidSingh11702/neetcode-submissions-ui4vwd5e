class StockSpanner {
    int day;
    stack<pair<int,int>> s;
public:
    StockSpanner() {
        day = 1;
    }
    
    int next(int price) {
        while (!s.empty()) {
            auto top = s.top();
            if (top.first > price) {
                s.push({price,day});
                return (day++)-top.second;
            } else {
                s.pop();
            }
        }
        s.push({price,day});
        return day++;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */