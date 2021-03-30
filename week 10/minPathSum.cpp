class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        for(int y = 0; y < grid.size(); y++){
            for(int x = 0; x < grid[0].size(); x++){
                if(y == 0 && x == 0)
                    continue;
                
                if(y == 0){
                    grid[0][x] = grid[0][x] +  grid[0][x - 1];
                }else if(x == 0){
                    grid[y][0] = grid[y][0] +  grid[y - 1][0];
                }else{
                    grid[y][x] = min(grid[y - 1][x], grid[y][x - 1]) + grid[y][x];
                }
            }
        }
        return grid.back().back();
    }
};