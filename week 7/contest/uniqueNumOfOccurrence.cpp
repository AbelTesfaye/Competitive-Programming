class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> m;
        unordered_set<int> s;
        
        for(int n: arr){
            m[n]++;
        }
        
        for(auto &[k, v]: m){
            if(s.find(v) != s.end()){
                return false;
            }
            
            s.insert(v);
        }
        
        return true;
    }
};