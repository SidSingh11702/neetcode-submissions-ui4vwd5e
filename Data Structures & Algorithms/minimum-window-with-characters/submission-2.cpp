class Solution {
    int hasMissingChars(map<char,int>& freqS, map<char,int>& freqT) {
        for (auto &[k,v] : freqT) if (freqS[k] < v) return true;
        return false;
    }
public:
    string minWindow(string s, string t) {
        map<char,int> freqS, freqT;
        for (auto c : t) freqT[c]++;
        int n = s.size(), l = 0, r = 0, len = INT_MAX;
        string res;
        freqS[s[0]]++;
        while (r < n) {
            if (hasMissingChars(freqS,freqT)) {
                freqS[s[++r]]++; 
            } else {
                if (len > r-l+1) len = r-l+1, res = s.substr(l,r-l+1);
                freqS[s[l++]]--;
            }
        }
        return res;
    }
};
