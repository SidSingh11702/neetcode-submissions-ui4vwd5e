class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double,int>> v; vector<vector<int>> res;
        for (int i=0; i<points.size(); i++) v.push_back({pow(points[i][0],2)+pow(points[i][1],2),i});
        sort(begin(v), end(v));
        for (int i=0; i<k; i++) res.push_back(points[v[i].second]);
        return res;
    }
};
