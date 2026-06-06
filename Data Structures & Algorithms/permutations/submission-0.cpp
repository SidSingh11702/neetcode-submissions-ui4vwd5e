class Solution {
    void backtrack(vector<int>& curr, vector<pair<int,bool>>& remaining, vector<vector<int>>& res) {
        if (curr.size() == remaining.size()) {
            res.push_back(curr);
            return;
        }
        for (auto &p : remaining) if (p.second) curr.push_back(p.first), p.second = false, backtrack(curr,remaining,res), curr.pop_back(), p.second = true;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr; vector<vector<int>> res;
        vector<pair<int,bool>> remaining;
        for (int num : nums) remaining.push_back({num,true});
        backtrack(curr,remaining,res);
        return res;
    }
};
