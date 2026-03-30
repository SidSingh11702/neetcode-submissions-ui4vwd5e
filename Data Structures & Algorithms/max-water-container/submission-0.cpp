class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), l = 0, r = n-1, res = 0;
        while (l < r) {
            res = max(res, (r-l)*min(heights[l], heights[r]));
            if (heights[l] < heights[r]) l++; else r--;
        }
        return res;
    }
};
