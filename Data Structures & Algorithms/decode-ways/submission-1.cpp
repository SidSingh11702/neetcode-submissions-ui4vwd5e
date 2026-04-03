class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(); vector<int> dp(n,0);
        if (s[0] > '0') dp[0] = 1, dp[1] += s[1] > '0', dp[1] += stoi(s.substr(0,2)) <= 26;
        for (int i=2; i<n; i++) {
            if (s[i] > '0') dp[i] += dp[i-1];
            dp[i] += s[i-1] > '0' && stoi(s.substr(i-1,2)) <= 26 ? dp[i-2] : 0;
        }
        return dp.back();
    }
};
