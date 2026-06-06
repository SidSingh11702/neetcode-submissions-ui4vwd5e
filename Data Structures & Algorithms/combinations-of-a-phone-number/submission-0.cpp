class Solution {
    void backtrack(string curr, string digits, vector<string>& res) {
        if (digits.empty() && !curr.empty()) {
            res.push_back(curr);
            return;
        }
        char c = digits[0];
        if (c == '2') {
            backtrack(curr+'a',digits.substr(1),res), backtrack(curr+'b',digits.substr(1),res), backtrack(curr+'c',digits.substr(1),res);
        } else if (c == '3') {
            backtrack(curr+'d',digits.substr(1),res), backtrack(curr+'e',digits.substr(1),res), backtrack(curr+'f',digits.substr(1),res);
        } else if (c == '4') {
            backtrack(curr+'g',digits.substr(1),res), backtrack(curr+'h',digits.substr(1),res), backtrack(curr+'i',digits.substr(1),res);
        } else if (c == '5') {
            backtrack(curr+'j',digits.substr(1),res), backtrack(curr+'k',digits.substr(1),res), backtrack(curr+'l',digits.substr(1),res);
        } else if (c == '6') {
            backtrack(curr+'m',digits.substr(1),res), backtrack(curr+'n',digits.substr(1),res), backtrack(curr+'o',digits.substr(1),res);
        } else if (c == '7') {
            backtrack(curr+'p',digits.substr(1),res), backtrack(curr+'q',digits.substr(1),res), backtrack(curr+'r',digits.substr(1),res), backtrack(curr+'s',digits.substr(1),res);
        } else if (c == '8') {
            backtrack(curr+'t',digits.substr(1),res), backtrack(curr+'u',digits.substr(1),res), backtrack(curr+'v',digits.substr(1),res);
        } else if (c == '9') {
            backtrack(curr+'w',digits.substr(1),res), backtrack(curr+'x',digits.substr(1),res), backtrack(curr+'y',digits.substr(1),res), backtrack(curr+'z',digits.substr(1),res);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        backtrack("",digits,res);
        return res;
    }
};
