class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), closestElementIdx = n-1;
        for(int i=n-2; i>=0; i--) if(abs(arr[i]-x) <= abs(arr[closestElementIdx]-x)) closestElementIdx = i;
        int startIdx = max(0,closestElementIdx-k+1); closestElementIdx = startIdx+k-1;
        while(closestElementIdx+1<n && abs(arr[closestElementIdx+1]-x) < abs(arr[startIdx]-x)) startIdx++, closestElementIdx++;
        return vector<int>(arr.begin()+startIdx,arr.begin()+closestElementIdx+1);
    }
};