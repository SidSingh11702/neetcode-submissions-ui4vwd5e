class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = (n*(n+1))/2;
        vector<bool> dp(n,true);
        for (int i=n-2; i>=0; i--) for (int j=n-1; j>i; j--) if (s[i] == s[j] && dp[j-1]) dp[j] = true; else dp[j] = false, cnt--;
        return cnt;
    }
};
