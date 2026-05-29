class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> ms;
        for (int i=0; i<n; i++) {
            if (ms.count(nums[i])) return true;
            if (i >= k) ms.erase(nums[i-k]);
            ms.insert(nums[i]);
        }
        return false;
    }
};