class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1, res = nums[0];
        while (l <= r) {
            int mid = (l+r)/2;
            if (nums[mid] < nums[0]) res = min(res,nums[mid]), r = mid-1; else l = mid+1;
        }
        return res;
    }
};
