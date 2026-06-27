class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(),piles.end()), ans = r;
        while (l <= r) {
            int mid = (l+r)/2, cnt = 0;
            for (auto pile : piles) cnt += (pile+mid-1)/mid;
            if (cnt <= h) ans = mid, r = mid-1; else l = mid+1;
        }
        return ans;
    }
};
