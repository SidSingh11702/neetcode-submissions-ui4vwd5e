class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, r = 0, maxFreq = 1, res = 0;
        vector<int> freq(26, 0);
        freq[s[0]-'A']++;
        while (l < n && r < n) {
            if (r-l+1 > maxFreq+k) {
                if (freq[s[l++]-'A']-- == maxFreq) 
                    maxFreq = *max_element(freq.begin(), freq.end());
            } else {
                res = max(res, r-l+1), maxFreq = max(maxFreq, ++freq[s[++r]-'A']);
            }         
        }
        return res;
    }
};
