class Solution {
public: 
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        
        vector<int> inDegrees(numCourses);
        unordered_map<int, vector<int> > m;
        
        for(auto prerequisite: prerequisites){
            inDegrees[prerequisite[0]]++;
            m[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        for(int j = 0; j < numCourses; j++){
            queue<int> q;

            for(int i = 0; i < inDegrees.size(); i++){
                if(inDegrees[i] != 0) continue;

                q.push(i);
            }

            if(q.empty()) break;
            
            while(!q.empty()){
                int nodeToRemove = q.front(); q.pop();
                
                ret.push_back(nodeToRemove);
                
                inDegrees[nodeToRemove] = -1;
                
                for(int adjN: m[nodeToRemove]){
                    inDegrees[adjN]--;
                }
            }
        }
        
        for(int deg: inDegrees){
            if(deg > 0) return {};
        }
        
        return ret;
    }
};