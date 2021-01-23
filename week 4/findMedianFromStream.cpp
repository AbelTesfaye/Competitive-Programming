class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> ma;
    priority_queue< int, vector<int>, greater<int> > mi;
        
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // this is my max-heap, min-heap interchanged version of the leetcode official soution
        mi.push(num);
        
        ma.push(mi.top()); mi.pop();
        
        if(ma.size() > mi.size()){
            mi.push(ma.top()); ma.pop();    
        }
    }
    
    double findMedian() {
        if(ma.size() == mi.size()){
            return ((ma.top() + mi.top()) / (double) 2);
        }
        
        return mi.top();
    }
};