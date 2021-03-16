class Solution {
public:
    int leastQuiet = INT_MAX, leastQuietGuy;
    
    unordered_map<int, vector<int> > m;
    unordered_set<int> vis;
    
    void dfs(vector<int>& quiet, int currentPerson){
        if(vis.find(currentPerson) != vis.end()) return;
        
        vis.insert(currentPerson);
        
        if(quiet[currentPerson] < leastQuiet){
            leastQuietGuy = currentPerson;
            leastQuiet = quiet[currentPerson];
        }
        
        for(int r: m[currentPerson]){
            dfs(quiet, r);
        }
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {        
        for(auto r: richer){
            m[r[1]].push_back(r[0]);
        }
        
        vector<int> ret(quiet.size());
        
        for(int i = 0; i < quiet.size(); i++){
            leastQuiet = quiet[i];
            leastQuietGuy = i;

            dfs(quiet, i);
            
            ret[i] = leastQuietGuy;
            vis.clear();
        }
        
        return ret;
    }
};// [5,5,2,5,4,5,6,7]