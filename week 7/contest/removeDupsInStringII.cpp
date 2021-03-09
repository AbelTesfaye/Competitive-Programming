class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        bool shouldRemove = true;
        while(shouldRemove){
            string ret = "";

            shouldRemove = false;
            int prevCharCount = 0;
            
            // abcd
            
            for(int i = 0; i < s.size(); i++){
                char c = s[i];
                
                if(!ret.empty() && ret.back() == c) prevCharCount++;
                else prevCharCount = 1;
                
                ret += c;

                if(prevCharCount == k){
                    int r = k;
                    shouldRemove = true;
                    while(r--){
                        ret.pop_back();
                    }
                }
            }
            
            s = ret;
        }
        
        return s;
    }
};