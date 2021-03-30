class Solution {
public:
    unordered_map<int, int> m;
    
    int dfs(vector<int> &cost, int i){
        if(i < 0) return 0;
        if(m.find(i) != m.end()) return m[i];
        
        int lCost = dfs(cost, i - 1);
        int rCost = dfs(cost, i - 2);
        
        int c = 0;
        
        if(i != cost.size()) c = cost[i];
        
        return m[i] = min(lCost, rCost) + c;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        return dfs(cost, cost.size());
    }
};