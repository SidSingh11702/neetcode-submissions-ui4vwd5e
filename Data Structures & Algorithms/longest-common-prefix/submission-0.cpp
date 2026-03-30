class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(auto i=0; i<strs[0].size(); i++)
            for(auto str : strs)
                if(i == str.size() || str[i] != strs[0][i])
                    return str.substr(0,i);
        return strs[0];
    }
};