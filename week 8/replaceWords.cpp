class Solution {
public:
    struct TrieNode{
        char c = '*';
        bool isWord = false;
        unordered_map<char, TrieNode *> m;
    };
    
    TrieNode *root = new TrieNode{'*',false};
    
    void insert(string &w){
        TrieNode *prev = root;
        
        for(char c: w){
            if(prev->m[c] == NULL){
                prev->m[c] = new TrieNode{};
            }
            
            prev->m[c]->c = c;
            prev = prev->m[c];
        }
        
        prev->isWord = true;
        
    }
    
    string getShortestRoot(string &w){
        TrieNode *prev = root;
        
        string root = "";
        for(char c: w){
            root += c;
            if(prev->m[c] == NULL){
                return w;
            }
            
            if(prev->m[c]->isWord){
                return root;
            }
            
            prev = prev->m[c];
        }
        
        return w;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        for(string &st: dictionary){
            insert(st);
        }
        
        string ret = "";
        
        string word = "";
        for(int i = 0; i < sentence.size(); i++){
            char c = sentence[i];
            
            word += sentence[i];
            if(c == ' '){
                word.pop_back();
                
                // process word
                ret += getShortestRoot(word) + " ";
                word = "";
            }
        }
        
        // process word
        ret += getShortestRoot(word);
        
        
        return ret;
    }
};