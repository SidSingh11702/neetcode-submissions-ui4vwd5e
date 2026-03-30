class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), ans = 1;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for (int i=0; i<n; i++) dp[i][i] = true;
        for (int e=0; e<n; e++) for (int b=0; b<e; b++) if (s[b]==s[e] && (e-b==1 || dp[b+1][e-1])) dp[b][e] = true;
        string res;        
        for (int i=0; i<n; i++) for (int j=0; j<=i; j++) if (dp[j][i] && ans <= i-j+1) ans = i-j+1, res = s.substr(j,i-j+1);
        return res;
    }
};
