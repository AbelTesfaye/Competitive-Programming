class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> ma;
    priority_queue<int, vector<int>, greater<int>> mi;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        ma.push(num);
        mi.push(ma.top());ma.pop();
        
        if(mi.size() > ma.size()){
            ma.push(mi.top());mi.pop();
        }
    }
    
    double findMedian() {
        
        if(ma.size() > mi.size()){
            return ma.top();
        }
        
        return (ma.top() + mi.top()) / (double) 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */