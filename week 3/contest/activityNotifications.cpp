
int getNth(map<int, int> &om, int n){
    int passed = 0;
    for(auto &kv: om){
        passed += kv.second;
        
        if(passed >= n) return kv.first;
    }
    
    return -1;
}

// Complete the activityNotifications function below.
int activityNotifications(vector<int> exp, int d) {
    int ret = 0;
    
    map<int, int> om;
    
    for(int i = 0; i < d; i++) om[exp[i]]++;
        
    for(int i = d; i < exp.size(); i++){
        
        double median = getNth(om, (d/ 2) + 1);
        
        if((d & 1) == 0){
            median = ((getNth(om, d/ 2) + getNth(om, (d/ 2) + 1)) / (double)2);
        }
        
        if(exp[i] >= (2 * median)) {
            cout<<exp[i]<<"median: "<<median<<endl;
            ret++;
        }
        
        om[exp[i]]++;
        om[exp[i - d]]--;
    }

    return ret;
}
