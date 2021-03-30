class Solution {
public:   
    bool shouldInsert(vector<vector<int>>& grid, int x, int y){
        if(y == -1 || y == grid.size()) return false;
        if(x == -1 || x == grid[0].size()) return false;
        if(grid[y][x] != 0) return false;
        
        return true;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        using a3 = array<int, 3>;
        
        int ret = -1;
        
        queue< a3 > q;
        
        for(int y = 0; y < grid.size(); y++){
            for(int x = 0; x < grid[0].size(); x++){
                if(grid[y][x] == 1){
                    grid[y][x] = -1;
                    q.push({x, y, 0});
                }
            }
        }
        
        while(q.size()){
            auto [x, y, m] = q.front(); q.pop();
            
            if(grid[y][x] == 0){
                grid[y][x] = max(grid[y][x], m);
                ret = max(ret, grid[y][x]);  
            }
            
            if(shouldInsert(grid, x + 1, y)) q.push({x + 1, y, m + 1});
            if(shouldInsert(grid, x - 1, y)) q.push({x - 1, y, m + 1});
            
            if(shouldInsert(grid, x, y + 1)) q.push({x, y + 1, m + 1});
            if(shouldInsert(grid, x, y - 1)) q.push({x, y - 1, m + 1});
        }
        
        return ret;
    }
};