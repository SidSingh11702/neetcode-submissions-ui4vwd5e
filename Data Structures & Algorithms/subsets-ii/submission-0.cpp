class Solution {
    void backtrack(vector<int>& curr, map<int,int>::iterator it, map<int,int>& cnt, vector<vector<int>>& res) {
        if (it == cnt.end()) {
            res.push_back(curr);
            return;
        }
        backtrack(curr,next(it),cnt,res);
        if (it->second > 0) curr.push_back(it->first), it->second--, backtrack(curr,it,cnt,res), curr.pop_back(), it->second++;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr; vector<vector<int>> res; map<int,int> cnt;
        for (int num : nums) cnt[num]++;
        backtrack(curr, cnt.begin(), cnt, res);
        return res;
    }
};
