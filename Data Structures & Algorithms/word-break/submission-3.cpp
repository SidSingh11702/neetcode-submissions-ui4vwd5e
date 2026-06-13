class Solution {
    map<string,bool> mp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        if (mp.count(s)) return mp[s];
        for (auto word : wordDict) if (s.find(word) == 0 && wordBreak(s.substr(word.size()), wordDict)) return mp[s] = true;
        return mp[s] = false;
    }
};
