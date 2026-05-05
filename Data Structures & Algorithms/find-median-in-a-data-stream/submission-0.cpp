class MedianFinder {
    priority_queue<int> maxPq;
    priority_queue<int, vector<int>, greater<int>> minPq;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxPq.push(num), minPq.push(maxPq.top()), maxPq.pop();
        if (minPq.size() > maxPq.size()) maxPq.push(minPq.top()), minPq.pop();
    }
    
    double findMedian() {
        return minPq.size() < maxPq.size() ? maxPq.top() : (minPq.top() + maxPq.top()) / 2.0;
    }
};
