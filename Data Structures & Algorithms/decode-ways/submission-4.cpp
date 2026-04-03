class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), prev = 0, ans = 0;
        if (s[0] > '0') prev = 1, ans += s[1] > '0', ans += stoi(s.substr(0,2)) <= 26;
        if (n == 1) return prev; else if (n == 2) return ans;
        for (int i=2; i<n; i++) {
            int curr = s[i] > '0' ? ans : 0;
            curr += s[i-1] > '0' && stoi(s.substr(i-1,2)) <= 26 ? prev : 0, prev = ans, ans = curr;
        }
        return ans;
    }
};
