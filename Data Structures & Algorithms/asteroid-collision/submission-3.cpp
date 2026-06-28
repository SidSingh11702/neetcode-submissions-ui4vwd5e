class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s; s.push(asteroids[0]); int n = asteroids.size(); vector<int> res;
        for (int i=1; i<n; i++) {
            if (asteroids[i] < 0 && !s.empty()) {
                int flag = false;
                while (!s.empty()) {
                    if (s.top() < 0) {
                        flag = true;
                        s.push(asteroids[i]);
                        break;
                    } else if (abs(asteroids[i]) == s.top()) {
                        flag = true;
                        s.pop();
                        break; 
                    } else if (abs(asteroids[i]) > s.top()) {
                        s.pop();
                    } else {
                        flag = true;
                        break;
                    }
                }
                if (s.empty() && !flag) s.push(asteroids[i]);
            } else {
                s.push(asteroids[i]);
            }
        }
        while(!s.empty()) res.push_back(s.top()), s.pop();
        reverse(res.begin(),res.end());
        return res;
    }
};