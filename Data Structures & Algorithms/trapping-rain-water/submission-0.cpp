class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), r = n-1, res = 0;
        vector<int> prefSum(n);
        prefSum[0] = height[0];
        for (int i=1; i<n; i++) prefSum[i] = prefSum[i-1] + height[i];
        while (r > 0) {
            int l = r-1, maxIdx = l;
            while (l >= 0 && height[l] < height[r]) {
                if (height[l] > height[maxIdx]) maxIdx = l;
                l--;
            }
            if (l >= 0) res += height[r] * (r-l-1) - (prefSum[r-1] - prefSum[l]), r = l; else res += height[maxIdx] * (r-maxIdx-1) - (prefSum[r-1] - prefSum[maxIdx]), r = maxIdx;
        }
        return res;
    }
};
