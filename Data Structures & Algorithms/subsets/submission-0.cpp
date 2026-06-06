class Solution {
    void backtrack(int idx, vector<int>& curr, vector<int>& nums, vector<vector<int>>& res) {
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }
        backtrack(idx+1,curr,nums,res), curr.push_back(nums[idx]), backtrack(idx+1,curr,nums,res), curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr; vector<vector<int>> res;
        backtrack(0,curr,nums,res);
        return res;
    }
};
