class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ret = 0;
        int prevX = 0;
        for(int y = grid.size() - 1; y != -1; y--){
            for(int x = prevX; x < grid[0].size(); x++){
                
                if(grid[y][x] < 0){
                    ret += (grid[0].size() - x);
                    break;
                }
                
                prevX = x;
            }
        }
        return ret;
    }
};