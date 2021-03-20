class Solution {
public:
    unordered_map<char, int> s1m, s2m;
    
    bool isFirstContainedInSecond(){
        
        for(auto [c, f]: s1m){
            if(s2m[c] < f) return false;
        }
        
        return true;
    }
    
    bool isFirstPermutationOfSecond(){
        
        for(auto [c, f]: s2m){
            if(s1m[c] != f) return false;
        }
        
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        for(char c: s1) s1m[c]++;
        
        int l = 0;
        int r = 0;
        
        while(!isFirstContainedInSecond() && r < s2.size()){
            char rc = s2[r];
            
            s2m[rc]++;
            
            while(l <= r && isFirstContainedInSecond()){       
                if(isFirstPermutationOfSecond()){
                    if(r - l + 1 == s1.size()){
                        return true;
                    }
                    break;
                }
                // shrink to size
                char lc = s2[l];
                s2m[lc]--;
                l++;
            }
            r++;
        }
        
        return false;
    }
};