class Solution {
public:
    struct TrieNode{
        char c = '*';
        unordered_map<char, TrieNode*> children;
        bool isWord = true;
        int count = 0;
    };
    
    TrieNode *root = new TrieNode;
    
    void insert(string s){
        TrieNode *prev = root;
        
        for(char c: s){
            if(!prev->children[c]){
                prev->children[c] = new TrieNode{c};
            }
            
            prev->count++;
            prev = prev->children[c];
        }
        
        prev->count++;
        prev->isWord = true;
    }
    
    string getLCP(){
        string ret = "";
        
        TrieNode *prev = root;
        
        while(prev->children.size() == 1){
            prev = prev->children.begin()->second;
            
            if(prev->count != root->count){
                break;
            }
            ret += prev->c;
        }
        
        return ret;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        for(string s: strs){
            insert(s);
        }
        
        return getLCP();
    }
};