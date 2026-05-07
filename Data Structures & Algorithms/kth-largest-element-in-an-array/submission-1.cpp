class Solution {
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right], i = left;
        for (int j = left; j < right; j++) if (nums[j] <= pivot) swap(nums[i++], nums[j]);
        swap(nums[i], nums[right]);
        return i;
    }

    int quickSelect(vector<int>& nums, int left, int right, int idx) {
        int pivotIndex = partition(nums, left, right);
        return pivotIndex == idx ? nums[pivotIndex] : pivotIndex < idx ? quickSelect(nums, pivotIndex+1, right, idx) : quickSelect(nums, left, pivotIndex-1, idx);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    }
};
