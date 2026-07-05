class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26,0);
        for (auto c : tasks) cnt[c-'A']++;
        sort(begin(cnt),end(cnt));
        int maxFreq = cnt.back(), idleSlots = (maxFreq-1)*n;
        for (int i=24; i>=0; i--) idleSlots -= min(cnt[i],maxFreq-1);
        return max(0,idleSlots) + tasks.size();
    }
};
