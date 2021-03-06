class Solution {
public:
    unordered_map<int, pair<int, vector<int> > > m;
    
    int dfs(int id){
        
        int sums = m[id].first;
        for(int adj: m[id].second){
            
            sums += dfs(adj);
        }
            
        return sums;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        for(auto &emp: employees){
            m[emp->id].first = emp->importance;
            for(int id: emp->subordinates){
                 m[emp->id].second.push_back(id);
            }
        }
        
        return dfs(id);
    }
};