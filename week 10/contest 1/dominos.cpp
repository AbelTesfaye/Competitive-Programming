class Solution {
public:
    unordered_map<string, int> m;
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ret = 0;
        for(auto d: dominoes){
            
            int mi = min(d[0], d[1]);
            int ma = max(d[0], d[1]);
            
            string key1 = to_string(mi) + "," + to_string(ma);
            
            if(m.find(key1) != m.end()) ret += m[key1];
            
            m[key1]++;
        }
        return ret;
    }
};