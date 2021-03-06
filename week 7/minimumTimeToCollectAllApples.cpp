class Solution {
public:
    int v = 0;
    
    unordered_map<int, int> vm;
    unordered_map<int, vector<int>> em;
    
    bool isConnectedToApplePath(int node){
        for(int e: em[node]){
            if(vm[e] == 1) return true;
        }
        
        return false;
    }
    
    void dfs(int currentNode, vector<bool>& hasApple){
        
        vm[currentNode] = -1;
        
        for(int e: em[currentNode]){
            if(vm[e] != 0) continue;
            
            dfs(e, hasApple);
        }
        
        if(hasApple[currentNode] || isConnectedToApplePath(currentNode)) {
            v++;
            vm[currentNode] = 1;
        }
            
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    
        for(auto &e: edges){
            em[e[0]].push_back(e[1]);
            em[e[1]].push_back(e[0]);

        }
        
        dfs(0, hasApple);
        
        if(v == 0) return 0;
        
        return 2 * (v - 1);
    }
};
