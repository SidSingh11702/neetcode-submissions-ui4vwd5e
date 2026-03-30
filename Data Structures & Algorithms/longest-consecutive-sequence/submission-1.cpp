class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), ans = 1, cnt = 1;
        for (int i=1; i<n; i++) if (nums[i] == nums[i-1]+1) cnt++; else if (nums[i] != nums[i-1]) ans = max(ans,cnt), cnt = 1;
        return n ? max(ans,cnt) : 0;
    }
};
