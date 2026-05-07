class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), cnt = 0;
        vector<pair<int,float>> v;
        for (int i=0; i<n; i++) v.push_back({position[i],(target-position[i])/(float)speed[i]});
        sort(v.begin(),v.end());
        float maxTillNow = 0; 
        for (int i=n-1; i>=0; i--) if (v[i].second > maxTillNow) maxTillNow = v[i].second, cnt++;
        return cnt;
    }
};
