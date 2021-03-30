class Solution {
public:
    unordered_set<string> s;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> ret(n, -1);
        
        using a3 = array<int, 3>;
        
        unordered_map<int, unordered_set<int> > re, be;
        
        for(auto ed: red_edges) re[ed[0]].insert(ed[1]);
        for(auto ed: blue_edges) be[ed[0]].insert(ed[1]);
        
        queue<a3> q;
        
        q.push({0, 0, 0});
        q.push({0, 1, 0});
        
        while(q.size()){
            auto [nodeId, takeRed, pathLen] = q.front(); q.pop();
            
            string key = to_string(nodeId) + ","+to_string(takeRed);
            if(s.find(key) != s.end()) continue;
            s.insert(key);
            
            if(ret[nodeId] == -1) ret[nodeId] = pathLen;
            
            if(takeRed){
                for(auto next: re[nodeId]){
                    q.push({next, 0, pathLen + 1});
                }
            } else {
                for(auto next: be[nodeId]){
                    q.push({next, 1, pathLen + 1});
                }
            }
        }
        
        return ret;
    }
};