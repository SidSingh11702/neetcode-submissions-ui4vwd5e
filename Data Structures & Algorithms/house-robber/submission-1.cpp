class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), prev = nums[0], max_before_prev = 0, res = nums[0];
        for (int i=1; i<n; i++) {
            int ans = nums[i] + max_before_prev;
            max_before_prev = max(max_before_prev, prev), prev = ans, res = max(res, ans);
        }
        return res;
    }
};
