/*
 space O(n)
 time O(n^2)
*/
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

/*
 time and space O(n), yet slower than the above
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {        
        stack< pair<char, int>  > st;
        
        for(char c: s){
            if(st.empty()){
                st.push({c,1});
            } else{
                if(st.top().first == c){
                    st.top().second++;
                } else {
                    st.push({c, 1});
                } 
            }
            
            if(st.top().second == k){
                st.pop();
            }
        }
       
        string ret = "";
        
        while(!st.empty()){
            auto [c, n] = st.top();
            ret += string(n, c); st.pop();
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};