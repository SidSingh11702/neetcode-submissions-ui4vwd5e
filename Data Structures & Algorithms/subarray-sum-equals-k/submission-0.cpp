class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
        vector<int> pref_sum; pref_sum.push_back(0);
        for(auto i : nums) pref_sum.push_back(pref_sum.back() + i);
        for(auto i=0; i<n; i++)
            for(auto j=0; j<=i; j++)
                if(pref_sum[i+1] - pref_sum[j] == k)
                    res++;
        return res;
    }
};