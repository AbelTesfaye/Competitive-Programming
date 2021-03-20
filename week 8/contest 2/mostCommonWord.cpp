class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> b;
        unordered_map<string, int> m;
        
        for(string &s: banned){
            b.insert(s);
        }
        
        string word = "";
        for(int i = 0; i < paragraph.size(); i++){
            char c = tolower(paragraph[i]);
            word += c;
            
            if(c < 'a' || c > 'z'){
                word.pop_back();
                
                // cout<<word<<endl;
                // processWord
                if(b.find(word) == b.end()) m[word]++;
                
                word = "";
            }
        }
        
        if(b.find(word) == b.end()) m[word]++;
        
        pair<string, int> maxWord = {"", -1};
        
        for(auto &[s, f]: m){
            // cout<<s<<f<<endl;
            if(f > maxWord.second && s != ""){
                maxWord = {s, f};
            }
            
        }
        
        return maxWord.first;
    }
};