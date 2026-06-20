class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> cnt1(26,0), cnt2(26,0);
        for (auto c : s1) cnt1[c-'a']++;
        for (int i=0; i<n; i++) {
            cnt2[s2[i]-'a']++;
            if (i >= m) cnt2[s2[i-m]-'a']--;
            if (cnt1 == cnt2) return true;
        }
        return false;
    }
};
