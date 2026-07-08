class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n,0), outDegree(n,0);
        for (auto edge : trust) inDegree[edge[1]-1]++, outDegree[edge[0]-1]++;
        int res = -1;
        for (int i=0; i<n; i++) if (inDegree[i] == n-1 && outDegree[i] == 0) if (res == -1) res = i+1;
        return res;
    }
};