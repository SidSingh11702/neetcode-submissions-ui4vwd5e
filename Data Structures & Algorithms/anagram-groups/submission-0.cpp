class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp; vector<vector<string>> res;
        for (auto str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end()), mp[sorted].push_back(str);
        }
        for (auto [k,v] : mp) res.push_back(v);
        return res;
    }
};
