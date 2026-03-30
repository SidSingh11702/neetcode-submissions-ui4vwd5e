class Solution {
public:
    int climbStairs(int n) {
        int prev = 1, prevToPrev = 1, ans = 2;
        for (int i=2; i<n; i++) prevToPrev = prev, prev = ans, ans = prev + prevToPrev;
        return n == 1 ? 1 : ans;
    }
};
