class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>, vector<string>> mp; vector<vector<string>> res;
        for (auto str : strs) {
            map<char,int> cnt;
            for (auto c : str) cnt[c]++;
            mp[cnt].push_back(str);
        }
        for (auto [k,v] : mp) res.push_back(v);
        return res;
    }
};
