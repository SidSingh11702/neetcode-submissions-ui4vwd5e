class Solution {
    int robHelper(const vector<int>& nums) {
        int n = nums.size(), prevToPrev = 0, prev = 0, ans = 0; 
        for (auto num : nums) ans = max(prev, num + prevToPrev), prevToPrev = prev, prev = ans;
        return ans;
    }
public:
    int rob(vector<int>& nums) {
        return max(nums[0], max(robHelper(vector<int>(nums.begin()+1,nums.end())), robHelper(vector<int>(nums.begin(),nums.end()-1))));
    }
};
