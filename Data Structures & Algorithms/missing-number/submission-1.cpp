class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), xorr = 0;
        for (int i=0; i<n; i++) xorr ^= i ^ nums[i];
        return xorr ^ n;
    }
};
