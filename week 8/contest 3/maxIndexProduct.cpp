long long solve(vector<int> arr) {
    
    int n = arr.size();
    vector<int> l(n), r(n);
    
    stack< pair<int, int> > s; // index, value 
    
    for(int i = 0; i < arr.size(); i++){
        
        while(!s.empty() && s.top().second <= arr[i]){
            s.pop();
        }
        
        if(s.empty()){
            l[i] = 0;
        } else {
            l[i] = s.top().first;
        }
        
        s.push({i + 1, arr[i]});
    }
    
    while(!s.empty()) s.pop();
    
    for(int i = arr.size() - 1; i != -1; i--){
        
        while(!s.empty() && s.top().second <= arr[i]){
            s.pop();
        }
        
        if(s.empty()){
            r[i] = 0;
        } else {
            r[i] = s.top().first;
        }
        
        s.push({i + 1, arr[i]});
    }
    
    long long ret = 0;
    
    for(int i = 0; i < arr.size(); i++){
        
        ret = max(ret, (l[i]) * (long long)(r[i]));
        
    }
    
    return ret;
    
}