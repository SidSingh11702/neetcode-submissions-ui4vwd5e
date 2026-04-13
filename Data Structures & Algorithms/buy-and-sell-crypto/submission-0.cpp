class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = INT_MAX, res = 0;
        for (auto price : prices) res = max(res, price-minTillNow), minTillNow = min(minTillNow, price);
        return res;
    }
};
