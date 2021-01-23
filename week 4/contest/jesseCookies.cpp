int cookies(int k, vector<int> A) {
    /*
     * Write your code here.
     */
    
    if(A.size() <= 1) return -1;
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    int ret = 0;
    
    for(int n: A) pq.push(n);
    
    while(pq.top() < k){
        int first = pq.top(); pq.pop();
        if(pq.size() == 0) return -1;
        int second = pq.top(); pq.pop();
        
        int newCookie = (first) + (second * 2);
        
        pq.push(newCookie);
        
        ret++;        
    }
        
    return ret;
}
