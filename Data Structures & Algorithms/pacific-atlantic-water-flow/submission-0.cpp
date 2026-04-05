class Solution {
    void dfs(int i, int j, vector<vector<int>>& heights, int m, int n, set<pair<int,int>>& res) {
        if (res.count({i,j})) return; else res.insert({i,j});
        if (i > 0 && heights[i-1][j] >= heights[i][j]) dfs(i-1,j,heights,m,n,res);
        if (j > 0 && heights[i][j-1] >= heights[i][j]) dfs(i,j-1,heights,m,n,res);
        if (i < m-1 && heights[i+1][j] >= heights[i][j]) dfs(i+1,j,heights,m,n,res);
        if (j < n-1 && heights[i][j+1] >= heights[i][j]) dfs(i,j+1,heights,m,n,res);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        set<pair<int,int>> atlantic, pacific;
        vector<vector<int>> res;
        for (int i=0; i<m; i++) dfs(i,0,heights,m,n,pacific), dfs(i,n-1,heights,m,n,atlantic);
        for (int j=0; j<n; j++) dfs(0,j,heights,m,n,pacific), dfs(m-1,j,heights,m,n,atlantic);
        for (auto v : atlantic) if (pacific.count(v)) res.push_back({v.first, v.second});
        return res;
    }
};
