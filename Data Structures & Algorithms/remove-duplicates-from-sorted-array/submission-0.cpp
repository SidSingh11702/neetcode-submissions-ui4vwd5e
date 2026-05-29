class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), k = 0;
        for (int i=0; i<n; i++) if (nums[k] != nums[i]) swap(nums[++k], nums[i]);
        return k+1;
    }
};