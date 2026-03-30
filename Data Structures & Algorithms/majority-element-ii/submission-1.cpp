class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), cnd1 = INT_MIN, cnd2 = INT_MIN, cnt1 = 0, cnt2 = 0;
        for (auto i : nums) {
            if (i == cnd1) {
                cnt1++;
            } else if (i == cnd2) {
                cnt2++;
            } else if (cnt1 == 0) {
                cnd1 = i, cnt1++;
            } else if (cnt2 == 0) {
                cnd2 = i, cnt2++;
            } else {
                cnt1--, cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for (auto i : nums) {
            if (i == cnd1) cnt1++;
            if (i == cnd2) cnt2++;
        }

        vector<int> res;
        if (cnt1 > n/3) res.push_back(cnd1); 
        if (cnt2 > n/3) res.push_back(cnd2);
        return res;    
    }
};