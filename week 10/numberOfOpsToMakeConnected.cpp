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
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent = vector<int>(n);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        int ret = 0;
        
        for(auto c: connections){
            int ca = c[0];
            int cb = c[1];
            
            int pca = find(ca);
            int pcb = find(cb);
            
            if(pca == pcb){
                ret++;
                continue;
            }
            
            Union(ca, cb);
        }
        
        int rootNodes = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i) rootNodes++;
        }
        
        if((rootNodes - 1) > ret) return -1;
        
        return rootNodes - 1;
    }
};