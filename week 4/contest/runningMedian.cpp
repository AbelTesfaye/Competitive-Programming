vector<double> runningMedian(vector<int> a) {
    /*
     * Write your code here.
     */
    
    priority_queue<int> ma;
    priority_queue<int, vector<int>, greater<int> > mi;
    
    vector<double> ret;
    
    for(int n: a){
        
        mi.push(n);
        
        if(mi.size() > ma.size()){
            int r = mi.top(); mi.pop();
            ma.push(r);
        }
        
        if(ma.size() > mi.size()) {
            ret.push_back(ma.top());
        }
        else{
            ret.push_back((mi.top() + ma.top()) / (double)2);
        }
        
    }
    
    return ret;
}