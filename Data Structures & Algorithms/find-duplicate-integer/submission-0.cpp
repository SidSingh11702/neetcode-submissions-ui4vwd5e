class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int num : nums) {
            if (nums[abs(num)] < 0) return abs(num);
            nums[abs(num)] = -abs(nums[abs(num)]);
        }
    }
};
