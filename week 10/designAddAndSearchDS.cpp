class WordDictionary {
public:
    struct TrieNode {
        char c = '*';
        bool isWord = false;
        unordered_map<char, TrieNode*> children;
    };
    
    TrieNode *root = new TrieNode;
    
    void insert(string &s){
        TrieNode *prev = root;
        
        for(char c: s){
            if(!prev->children[c]) prev->children[c] = new TrieNode{c};
            
            prev = prev->children[c];
        }
        
        prev->isWord = true;
    }
    
    bool search(string s, int i, TrieNode *prev){
        if(i == s.size() && prev->isWord) return true;
        if(s[i] != '.' && prev->children.find(s[i]) == prev->children.end()) return false;
        
        if(s[i] == '.'){
            for(auto [c, adj]: prev->children){
                bool r = search(s, i + 1, adj);
                
                if(r) return true;
            }
            
        } else {
            return search(s, i + 1, prev->children[s[i]]);
        }
        
        return false;
    }
    
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */