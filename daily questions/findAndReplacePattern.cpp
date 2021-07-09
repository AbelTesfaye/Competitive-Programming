class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        
        for(auto &s: words){
            unordered_map<char, char> m1, m2;
            
            bool shouldAdd = true;
            for(int i = 0; i < s.size(); i++){
                char wc = s[i];
                char pc = pattern[i];
                
                if(
                    (m1.find(pc) != m1.end() && m1[pc] != wc) ||
                    (m2.find(wc) != m2.end() && m2[wc] != pc)
                  ) {
                    shouldAdd = false;
                    break;
                }
                
                m1[pc] = wc;
                m2[wc] = pc;
            }
            
            if(shouldAdd){
                ret.push_back(s);
            }
        }
        
        return ret;
    }
};