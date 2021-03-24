class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > pq;
    int maxSize = -1;
    
    void addWithoutExceedingMaxSize(int n){
        pq.push(n);
        
        if(pq.size() > maxSize) pq.pop();
    }
    
    KthLargest(int k, vector<int>& nums) {
        maxSize = k;
        
        for(int n: nums) {
            addWithoutExceedingMaxSize(n);
        }
    }
    
    int add(int val) {
        addWithoutExceedingMaxSize(val);
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */