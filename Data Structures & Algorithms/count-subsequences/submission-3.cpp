class Solution {
    map<string,map<string,int>> dp;
public:
    int numDistinct(string s, string t) {
        if (t.empty()) return dp[s][t] = 1;
        if (s.empty()) return dp[s][t] = 0;
        if (dp.count(s) && dp[s].count(t)) return dp[s][t];
        if (s[0] == t[0]) return dp[s][t] = numDistinct(s.substr(1),t) + numDistinct(s.substr(1),t.substr(1));
        return dp[s][t] = numDistinct(s.substr(1),t);
    }
};