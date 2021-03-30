class Solution {
public:
    void Union(vector<int> &parent, int x, int y){
        int xParent = find(parent, x);
        int yParent = find(parent, y);
        
        if(xParent != yParent)
            parent[xParent] = yParent;
        
    }
    int find(vector<int>& parent, int i){
        if(parent[i] == -1)
            return i;
        
        return find(parent, parent[i]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> badEdge = {-1,-1};
        
        vector<int> parent(edges.size()+1, -1);
        
        for(auto edge : edges){
            int mi = min(edge[0], edge[1]);
            int ma = max(edge[0], edge[1]);
            
            int miParent = find(parent, mi);
            int maParent = find(parent, ma);
            
            if(miParent == maParent){
                badEdge = edge;
            }
            
            Union(parent, miParent, maParent);
            
            
        }
        
        return badEdge;
    }
};