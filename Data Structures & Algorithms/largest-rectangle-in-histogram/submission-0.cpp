class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), ans = 0;
        stack<int> s;
        for (int i=0; i<=n; i++) {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
                int height = heights[s.top()];
                s.pop();
                ans = max(ans, height * (s.empty() ? i : i-s.top()-1));
            }
            s.push(i);
        }
        return ans;
    }
};
