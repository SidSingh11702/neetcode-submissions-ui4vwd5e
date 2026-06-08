class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = (n*(n+1))/2;
        vector<vector<bool>> dp(n,vector<bool>(n,true));
        for (int i=n-2; i>=0; i--) for (int j=i+1; j<n; j++) if (s[i] != s[j] || dp[i+1][j-1] == false) dp[i][j] = false, cnt--;
        return cnt;
    }
};
