
// Complete the gridlandMetro function below.
long long int gridlandMetro(int n, int mm, int k, vector<vector<int>> track) {
    long long int ret = n * (long long) mm;
    
    unordered_map<int, vector< vector<int> > > m, merged;
    
    for(auto t: track){
        int y = t[0];
        int sx = t[1];
        int ex = t[2];
        
        m[y].push_back({sx, ex});
    }
    
    for(auto [y, cols]: m){
        sort(cols.begin(), cols.end(), [](vector<int> a1, vector<int> a2){
            if(a1[0] == a2[0]) return a1[1] < a2[1];
            
            return a1[0] < a2[0];
        });
        
        for(auto interval: cols){
           if(merged[y].empty() || merged[y].back()[1] < interval[0]){
               merged[y].push_back(interval);
            } else {
               merged[y].back()[1] = max(merged[y].back()[1], interval[1]);
            } 
        }
    }
    
    long long int trackSpaces = 0;
    for(auto [y, intervals]: merged){
        for(auto in: intervals){
            // cout<<y<<" "<<in[0]<<" "<<in[1]<<endl;
            
            int trackSize = in[1] - in[0] + 1;
            trackSpaces += trackSize;
        }
    }

    // cout<<"ret: "<<ret<<" trackSpaces: "<<trackSpaces<<endl;
    
    return ret - trackSpaces;
    // return (long long)n * (long long)mm;
}