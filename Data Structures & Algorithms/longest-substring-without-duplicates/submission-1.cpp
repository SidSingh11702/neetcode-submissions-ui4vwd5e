class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        map<char,int> count;
        for(int i = 0, j = 0; j < n; j++){
            if(++count[s[j]] > 1) {
                while(--count[s[i]] < 1) i++; i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};
