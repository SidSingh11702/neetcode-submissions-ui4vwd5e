class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, sum = nums[0], len = INT_MAX;
        while (r < n) if (sum < target) sum += nums[++r]; else len = min(len, r-l+1), sum -= nums[l++];
        return len % INT_MAX;
    }
};