class Trie {
public:
    struct TrieNode{
        unordered_map<char, TrieNode*> m;
        bool isWord;
    };
    
    TrieNode head = TrieNode();
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *prevNode = &head;
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            
            if(prevNode->m[c] == NULL){
                prevNode->m[c] = new TrieNode();
            }
                
            if(i == word.size() - 1){
                prevNode->m[c]->isWord = true;
            }
            
            prevNode = prevNode->m[c];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *prevNode = &head;
        
        for(int i = 0; i < word.size(); i++){
            char c = word[i];
            
            if(prevNode->m[c] == NULL){
                return false;
            }
            
            if(i == word.size() - 1){
                if(!prevNode->m[c]->isWord){
                    return false;
                }
            }
            
            prevNode = prevNode->m[c];
        }
        
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *prevNode = &head;
        
        for(int i = 0; i < prefix.size(); i++){
            char c = prefix[i];
            
            if(prevNode->m[c] == NULL){
                return false;
            }
            
            prevNode = prevNode->m[c];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */