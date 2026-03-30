class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.begin(), nums.end());
        for (int i=1; i<n; i++) {
            int ans = 0;
            for (int j=0; j<i-1; j++) ans = max(ans, dp[j]);
            dp[i] += ans;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
