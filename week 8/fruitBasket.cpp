class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> m;
        
        int l = 0, r = 0;
        int ret = 0;
        
        while(r < tree.size()){
            m[tree[r]]++;
            
            // if basket is invalid, remove left item then check if valid
            while(m.size() > 2){
                m[tree[l]]--;
                
                if(m[tree[l]] == 0) {
                    m.erase(tree[l]);
                }
                
                l++;
            }
                            
            ret = max(ret, r - l + 1);
            
            r++;
        }
        
        return ret;
    }
};