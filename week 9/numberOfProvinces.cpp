class Solution {
public:
    vector<int> parent;
    
    int find(int n){
        int p = parent[n];
        
        while(p != parent[p]){
            p = parent[p];
        }
        
        return p;
    }
    
    void Union(int a, int b){
        int pa = find(a);
        int pb = find(b);
        
        parent[pb] = pa;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        parent = vector<int>(n);
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(!isConnected[y][x]) continue;
                
                Union(x, y);
            }
        }
        
        unordered_set<int> s;
        for(int p: parent) s.insert(p);
        
        return s.size();
    }
};