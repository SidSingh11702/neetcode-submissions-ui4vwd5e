class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, cnd;
        for (int num : nums) if (cnt == 0) cnd = num, cnt = 1; else if (cnd == num) cnt++; else cnt--;
        return cnd;
    }
};