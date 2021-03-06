class Solution {
public:   
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(n);
        unordered_map<int, vector<int>> graph;
        
        for(auto p: prerequisites){
            inDegree[p[0]]++;
            graph[p[1]].push_back(p[0]);
        }
        
        queue<int> q;
        
        for(int i=0; i<inDegree.size(); i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        int popCount = 0;
        while(!q.empty()){
            int poppedNode = q.front(); q.pop();
            popCount++;
            
            for(int adjNode: graph[poppedNode]){
                inDegree[adjNode]--;
                
                if(inDegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
        
        
        return popCount == n;
    }
};