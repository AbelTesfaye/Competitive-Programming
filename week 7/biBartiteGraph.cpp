class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(),0);
        queue<int> l;
        
        for(int src=0;src<graph.size(); src++){
            if(vis[src] != 0) 
                continue;
                        
            l.push(src);
            int currentRowColor = 1;
            while(l.size()>0){
                int popsAllowed = l.size();
                while(popsAllowed > 0){
                    int currentNode = l.front(); l.pop();
                    vis[currentNode] = currentRowColor;
                    
                    for(int adjN: graph[currentNode]){
                        if(vis[adjN] == 0){
                            l.push(adjN);
                        }else {
                            if(vis[adjN] == currentRowColor){
                                return false;
                            }
                        }
                    }
                    popsAllowed--;
                }
                if(currentRowColor == 2)
                    currentRowColor = 1;
                else
                    currentRowColor = 2;
            }            
        }
        
        return true;
    }
};