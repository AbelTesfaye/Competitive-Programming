static const auto _ = []() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}();
class Solution {
    private:
        string getSignature(string &str){
            vector<int> lettersFound(26,0);
            int sum = 0;
                        
            for(char &c: str){
                lettersFound[c-((int)'a')]++;
            }
            
            string outStr;
            for(int i: lettersFound)
                outStr+=to_string(i)+",";
             
            return outStr;
        }
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        vector< vector<string> > ret;
        unordered_map<string, vector<string> > hm;
        
        for(string& str: strs){
            string key = getSignature(str);
            hm[key].push_back(str);
        }
        
        for(auto kv: hm){
            ret.push_back(hm[kv.first]);
        }
           
        return ret;
    }
};