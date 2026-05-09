class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n,0);
        stack<pair<int,int>> s;
        for (int i=0; i<n; i++) {
            while (!s.empty() && s.top().first < temperatures[i]) {
                auto t = s.top(); s.pop();
                res[t.second] = i-t.second;
            }
            s.push({temperatures[i],i});
        }
        return res;
    }
};
