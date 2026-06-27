class Solution {
    int subarraysWithAtMostKDistinct(vector<int>& nums, int k) {
        map<int,int> cnt;
        int res = 0, l = 0;
        for (int r = 0; r < nums.size(); r++) {
            k -= !cnt[nums[r]]++;
            while (k < 0) k += !(--cnt[nums[l++]]);
            res += r-l+1;
        }
        return res;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums,k)-subarraysWithAtMostKDistinct(nums,k-1);
    }
};
