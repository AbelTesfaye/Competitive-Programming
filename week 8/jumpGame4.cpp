class Solution {
public:
    bool isValid(vector<int> &arr, int i){
        if(i < 0 || i >= arr.size()) return false;
        
        return true;
    }
    
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int> > mm;
        
        for(int i = 0; i < arr.size(); i++){
            mm[arr[i]].push_back(i);
        }
        
        unordered_set<int> vis;
        
        using a2 = array<int, 2>;
        
        queue< a2 > q;
        
        q.push( {0, 0} );
        
        while(!q.empty()){
            auto [i, m] = q.front(); q.pop();
            if(i == arr.size() - 1) return m;

            if(vis.find(i) != vis.end()) continue;
            vis.insert(i);
            
            // prev
            if(isValid(arr,i - 1) && vis.find(i - 1) == vis.end()){
                q.push({i - 1, m + 1});
            }
            
            // next
            if(isValid(arr,i + 1) && vis.find(i + 1) == vis.end()){
                q.push({i + 1, m + 1});
            }
            
            // neighbours
            for(int n: mm[arr[i]]){
                if(vis.find(n) != vis.end()) continue;
                q.push({n, m + 1});
            }
            
            mm[arr[i]].clear();
        }
        
        return -1;
    }
};