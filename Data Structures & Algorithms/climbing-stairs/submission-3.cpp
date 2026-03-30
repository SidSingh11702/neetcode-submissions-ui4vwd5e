class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, prevToPrev = 0, ans = 1;
        for (int i=1; i<n; i++) prevToPrev = prev, prev = ans, ans = prev + prevToPrev;
        return ans;
    }
};
