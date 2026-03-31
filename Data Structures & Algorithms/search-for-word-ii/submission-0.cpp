class Solution {
    bool dfs(int row, int col, vector<vector<char>>& board, int m, int n, string word, vector<vector<bool>>& visited) {
        if (word.empty()) return true; else if (row < 0 || row >= m || col < 0 || col >= n || visited[row][col] || board[row][col] != word[0]) return false; else visited[row][col] = true;
        if (dfs(row-1,col,board,m,n,word.substr(1),visited) || dfs(row+1,col,board,m,n,word.substr(1),visited) || dfs(row,col-1,board,m,n,word.substr(1),visited) || dfs(row,col+1,board,m,n,word.substr(1),visited)) return true;
        return visited[row][col] = false;
    }
    bool isPresent(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) for (int j=0; j<n; j++) if (dfs(i,j,board,m,n,word,visited)) return true;
        return false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        for (auto &word : words) if (isPresent(board, word)) res.push_back(word);
        return res;
    }
};
