class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        
        for(int n: answers) m[n]++;
        
        int ret = 0;
        
        for(auto &[o, f]: m){
            int fullSets = f / (o + 1);
            
            ret += (fullSets * (o + 1));
            
            int remainders = f % (o + 1);
            if(o == 0 || remainders == 0) continue;
            
            ret += o + 1;
        }
        
        return ret;
    }
};