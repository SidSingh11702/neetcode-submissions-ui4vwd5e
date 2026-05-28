class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        map<int,int> idx1;
        for (int i=0; i<n1; i++) idx1[nums1[i]] = i;
        vector<int> res(n1,-1);
        stack<int> s;
        for (int i=n2-1; i>=0; i--) {
            while (!s.empty() && s.top() < nums2[i]) s.pop();
            if (!s.empty() && idx1.count(nums2[i])) res[idx1[nums2[i]]] = s.top();
            s.push(nums2[i]);
        }
        return res;
    }
};