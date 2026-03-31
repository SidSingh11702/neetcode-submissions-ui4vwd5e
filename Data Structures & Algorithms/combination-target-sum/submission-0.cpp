class Solution {
    void combinationSum(vector<int>& nums, int target, int start, vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) res.push_back(curr); else if (target > 0) for (int i = start; i < nums.size(); i++) curr.push_back(nums[i]), combinationSum(nums, target - nums[i], i, curr, res), curr.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res; vector<int> curr;
        combinationSum(nums, target, 0, curr, res);
        return res;
    }
};