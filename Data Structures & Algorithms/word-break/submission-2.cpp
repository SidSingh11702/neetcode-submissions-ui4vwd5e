class Solution {
    map<string,bool> mp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        if (mp.count(s)) return mp[s];
        for (auto s1 : wordDict) if (!s.find(s1) && wordBreak(s.substr(s1.size()), wordDict)) return mp[s] = true;
        return mp[s] = false;
    }
};
