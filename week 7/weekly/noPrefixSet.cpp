struct TrieNode {
    char c = '*';
    bool isWord = false;
    unordered_map<char, TrieNode*> m;
};

TrieNode *root = new TrieNode{};

bool canAddWord(string &w){
    TrieNode *prev = root;
    
    for(int i = 0; i < w.size(); i++){
        char c = w[i];
                
        if(!prev->m[c]) prev->m[c] = new TrieNode{};
        
        if(prev->m[c]->isWord) return false;
        
        prev->m[c]->c = c;
        
        prev = prev->m[c];
    }
    
    prev->isWord = true;
    
    if(prev->m.size() != 0) return false;
    
    return true;
}
void noPrefix(vector<string> strings) {
    string B = "BAD SET";
    string G = "GOOD SET";
    
    for(string &s: strings){
        if(!canAddWord(s)) {
            cout<<B<<endl;
            cout<<s<<endl;
            return;
        }
    }

    cout<<G<<endl;
}