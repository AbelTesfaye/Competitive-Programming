class Solution {
public:
    string removeDuplicates(string S) {        
        stack< pair<char, int> > s;
        
        for(char c: S){
            if(!s.empty() && s.top().first == c) {
                s.top().second++;
            } else {
                s.push({c, 1});
            } 
            
            while(!s.empty() && s.top().second == 2){
                s.pop();
            }
        }
        
        string ret = "";
        while(!s.empty()){
            auto p = s.top(); s.pop();
            
            ret += string(p.second, p.first);
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};