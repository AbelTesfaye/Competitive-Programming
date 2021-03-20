class Solution {
public:
    unordered_map<char, int> m;
    int highestCount(unordered_map<char, int> &m){
        int ret = 0;
        
        for(auto kv: m)
            ret = max(ret, kv.second);
        
        return ret;
    }
    
    int characterReplacement(string s, int k) {
        int ret = 0;
        int l = 0;
        for(int r = 0; r < s.size(); r++){
            m[s[r]]++;
            if(r - l + 1 > highestCount(m) + k){
                m[s[l]]--;
                l++;
            }else{
                ret = max(ret, r - l + 1);
            }
        }
        
        return ret;
    }
};