class Solution {
    void backtrack(int sum, int target, vector<int>& curr, map<int,int>::iterator it, map<int,int>& cnt, vector<vector<int>>& res) {
        if (sum == target) {
            res.push_back(curr);
            return;
        }
        if (it == cnt.end() || sum > target) return;
        backtrack(sum,target,curr,next(it),cnt,res);
        if (it->second > 0) sum += it->first, curr.push_back(it->first), it->second--, backtrack(sum,target,curr,it,cnt,res), curr.pop_back(), it->second++;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr; vector<vector<int>> res; map<int,int> cnt;
        for (auto candidate : candidates) cnt[candidate]++;
        backtrack(0,target,curr,cnt.begin(),cnt,res);
        return res;
    }
};
