class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0;
        for(char c: s){
            bool isFound = false;
            for(int i = l; i < t.size(); i++){
                
                if(t[i] == c){
                    
                    isFound = true;
                    l = i + 1;
                    break;
                }
                
                if(i == t.size() - 1) return false;
            }
            
            if(!isFound){
                return false;
            }
            
        }
        
        return true;
    }
};