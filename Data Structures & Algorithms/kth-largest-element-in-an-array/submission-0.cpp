class Solution {
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right], i = left;
        for (int j = left; j < right; j++) if (nums[j] <= pivot) swap(nums[i++], nums[j]);
        swap(nums[i], nums[right]);
        return i;
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        int pivotIndex = partition(nums, left, right);
        return pivotIndex == k ? nums[pivotIndex] : pivotIndex < k ? quickSelect(nums, pivotIndex+1, right, k) : quickSelect(nums, left, pivotIndex-1, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    }
};
