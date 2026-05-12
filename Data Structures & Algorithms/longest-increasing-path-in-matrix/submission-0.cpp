class Solution {
    int dfs(int i, int j, int m, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[i][j]) return dp[i][j];
        if (i-1 >= 0 && matrix[i-1][j] > matrix[i][j]) dp[i][j] = max(dp[i][j],dfs(i-1,j,m,n,matrix,dp));
        if (i+1 < m && matrix[i+1][j] > matrix[i][j]) dp[i][j] = max(dp[i][j],dfs(i+1,j,m,n,matrix,dp));
        if (j-1 >= 0 && matrix[i][j-1] > matrix[i][j]) dp[i][j] = max(dp[i][j],dfs(i,j-1,m,n,matrix,dp));
        if (j+1 < n && matrix[i][j+1] > matrix[i][j]) dp[i][j] = max(dp[i][j],dfs(i,j+1,m,n,matrix,dp));
        return ++dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i=0; i<m; i++) for (int j=0; j<n; j++) res = max(res,dfs(i,j,m,n,matrix,dp));
        return res;
    }
};
