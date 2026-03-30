class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for (int num : nums) {
            if (!st.count(num-1)) {
                int len = 1;
                while (st.count(num+len)) len++;
                ans = max(ans,len);
            }
        }
        return ans;
    }
};
