class Solution {
public:
    int dfs(vector<vector<int>>& grid, int x, int y){
        if(y < 0 || x < 0 ||
            y >= grid.size() || x >= grid[0].size()) return 0;
        
        if(grid[y][x] == 0) return 0;
        
        int adjSum = 1;
        
        grid[y][x] = 0;
        
        adjSum += dfs(grid, x + 1, y);
        adjSum += dfs(grid, x - 1, y);
        adjSum += dfs(grid, x, y - 1);
        adjSum += dfs(grid, x, y + 1);
        
        return adjSum;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;
        
        for(int y = 0; y < grid.size(); y++){
            for(int x = 0; x < grid[0].size(); x++){      
                int currentArea = dfs(grid, x, y);
                ret = max(ret, currentArea);

            }
        }

        return ret;
        
    }
};