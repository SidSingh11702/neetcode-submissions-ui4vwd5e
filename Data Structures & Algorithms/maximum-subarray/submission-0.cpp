class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN; vector<int> prefSum(n+1); prefSum[0] = 0;
        for (int i=1; i<=n; i++) prefSum[i] = prefSum[i-1] + nums[i-1];
        for (int i=0; i<n; i++) for (int j=0; j<=i; j++) res = max(res, prefSum[i+1] - prefSum[j]);
        return res;
    }
};
