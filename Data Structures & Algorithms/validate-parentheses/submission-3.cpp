class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> openingBracket = {{')', '('}, {'}', '{'}, {']', '['}};
        for (char c : s) if (c == '(' || c == '{' || c == '[') st.push(c); else if (st.empty() || st.top() != openingBracket[c]) return false; else st.pop();
        return st.empty();
    }
};
