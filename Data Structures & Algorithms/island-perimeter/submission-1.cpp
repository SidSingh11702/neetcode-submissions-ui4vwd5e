class Solution {
    bool inWater(int i, int j, vector<vector<int>>& grid, int m, int n) {
        return i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0;
    }

    int dfs(int i, int j, vector<vector<int>>& grid, int m, int n, vector<vector<bool>>& vis) {
        if (inWater(i,j,grid,m,n) || vis[i][j]) return 0;
        vis[i][j] = true;
        return inWater(i-1,j,grid,m,n) + dfs(i-1,j,grid,m,n,vis) + inWater(i+1,j,grid,m,n) + dfs(i+1,j,grid,m,n,vis) + inWater(i,j-1,grid,m,n) + dfs(i,j-1,grid,m,n,vis) + inWater(i,j+1,grid,m,n) + dfs(i,j+1,grid,m,n,vis);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j])
                    return dfs(i,j,grid,m,n,vis);
        return 0;
    }
};