class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int, vector<int>, less<int>> maxHeap;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(minHeap.size() == maxHeap.size()){
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }else{
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        return minHeap.size() == maxHeap.size()? (minHeap.top() + maxHeap.top()) * 0.5
                                                : maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
