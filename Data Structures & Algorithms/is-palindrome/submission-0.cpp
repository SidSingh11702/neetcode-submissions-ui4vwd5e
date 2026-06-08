class Solution {
    bool isAlphaNumeric(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l < r) if (!isAlphaNumeric(s[l])) l++; else if (!isAlphaNumeric(s[r])) r--; else if (toupper(s[l++]) != toupper(s[r--])) return false;
        return true;
    }
};
