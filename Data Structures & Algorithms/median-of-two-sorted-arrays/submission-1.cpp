class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2,nums1);
        int l = 0, r = m, leftSize = (m+n+1)/2;
        while (l <= r) {
            int mid1 = (l+r)/2, mid2 = leftSize - mid1, l1 = mid1 > 0 ? nums1[mid1-1] : INT_MIN, l2 = mid2 > 0 ? nums2[mid2-1] : INT_MIN, r1 = mid1 < m ? nums1[mid1] : INT_MAX, r2 = mid2 < n ? nums2[mid2] : INT_MAX;
            if (l1 > min(r1,r2)) r = mid1-1; else if (l2 > min(r1,r2)) l = mid1+1; else if ((m+n)%2) return max(l1,l2); else return (max(l1,l2)+min(r1,r2))/2.0;
        }
    }
};
