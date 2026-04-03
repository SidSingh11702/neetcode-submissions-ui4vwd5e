class Solution {
    void dfs(int i, int j, vector<vector<char>>& grid, int m, int n, vector<vector<bool>>& visited) {
        if (i < 0 || i == m || j < 0 || j == n || visited[i][j] || grid[i][j] == '0') return;
        visited[i][j] = true, dfs(i-1,j,grid,m,n,visited), dfs(i+1,j,grid,m,n,visited), dfs(i,j-1,grid,m,n,visited), dfs(i,j+1,grid,m,n,visited);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i=0; i<m; i++) for (int j=0; j<n; j++) if (!visited[i][j] && grid[i][j] == '1') dfs(i,j,grid,m,n,visited), count++;
        return count;
    }
};
