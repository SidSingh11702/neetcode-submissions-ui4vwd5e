class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> prefSum(n+1,0); 
        map<int,int> cnt; cnt[0] = 1;
        for (int i=1; i<=n; i++) prefSum[i] = prefSum[i-1] + nums[i-1], ans += cnt[prefSum[i]-k], cnt[prefSum[i]]++;
        return ans;
    }
};