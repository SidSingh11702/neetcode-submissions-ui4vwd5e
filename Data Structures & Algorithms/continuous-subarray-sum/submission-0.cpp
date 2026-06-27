class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        for (int len = 2; len <= n; len++) {
            int r = len-1, sum = 0;
            for (int i=0; i<=r; i++) sum += nums[i];
            if (sum%k == 0) return true;
            while (++r < n) {
                sum += nums[r]-nums[r-len];
                if (sum%k == 0) return true;
            }
        }
        return false;
    }
};