class Solution {
public:
    bool isContainedInFirst(unordered_map<char, int> &m1, unordered_map<char, int> &m2){
        
        for(auto kv: m2){
            if(m1[kv.first] < m2[kv.first])
                return false;
        }
        
        return true;
    }
    
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0 || t.size() > s.size()) return {};
        
        int l = 0;
        int r = 0;
        
        unordered_map<char, int> tm;
        unordered_map<char, int> sm;
        for(char c: t)
            tm[c]++;
        
        sm[s[0]]++;
        
        bool found = false;
        string ret = s;
        while(true){
            if(isContainedInFirst(sm, tm)){
                found = true;
                string t = s.substr(l, r - l + 1);
                if(t.size() < ret.size())
                    ret = t; 
                sm[s[l]]--;
                l++;
                
            }else{
                r++;
                if(r == s.size())
                    break;
                sm[s[r]]++;
                
            }
        }     
        
        if(!found) return "";
        return ret;
    }
};