class Solution {
public:
    vector<int> parent;
    
    int find(int n){
        int p = parent[n];
        
        while(p != parent[p]){
            p = parent[p];
        }
        
        return parent[n] = p;
    }
    
    void Union(int a, int b){
        int pa = find(a);
        int pb = find(b);
        
        parent[pa] = pb;
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        parent = vector<int>(26);
        
        for(int i = 0; i < parent.size(); i++) parent[i] = i;
        
        for(string &s: equations){
            if(s[1] == '!') continue;
            
            char l1 = s[0] - 'a', l2 = s[3] - 'a';
            Union(l1, l2);
        }
        
        for(string &s: equations){
            if(s[1] == '=') continue;
            char l1 = s[0] - 'a', l2 = s[3] - 'a';
            int pl1 = find(l1), pl2 = find(l2);
            
            if(pl1 == pl2) return false;
        }
        
        return true;
    }
};