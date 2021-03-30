class Solution {
public:
    vector<vector<char>> grid;
    
    bool isValid(int x, int y){
        if(y == -1 || y == grid.size()) return false;
        if(x == -1 || x == grid[0].size()) return false;
        
        return true;
    }
    
    int getAdjMineCount(int x, int y){
        int ret = 0;
        
        if(isValid(x + 1, y) && grid[y][x + 1] == 'M') ret++;
        if(isValid(x - 1, y) && grid[y][x - 1] == 'M') ret++;
        if(isValid(x, y + 1) && grid[y + 1][x] == 'M') ret++;
        if(isValid(x, y - 1) && grid[y - 1][x] == 'M') ret++;
        
        if(isValid(x + 1, y + 1) && grid[y + 1][x + 1] == 'M') ret++;
        if(isValid(x - 1, y + 1) && grid[y + 1][x - 1] == 'M') ret++;
        if(isValid(x - 1, y - 1) && grid[y - 1][x - 1] == 'M') ret++;
        if(isValid(x + 1, y - 1) && grid[y - 1][x + 1] == 'M') ret++;
        
        return ret;
    }
    
    void revealEmpty(int x, int y){
        if(!isValid(x, y)) return;
        
        if(grid[y][x] != 'E') return;
            
        int adjCount = getAdjMineCount(x, y);
        if(adjCount > 0){
            grid[y][x] = '0' + adjCount;
            return;
        }
        
        grid[y][x] = 'B';
        
        revealEmpty(x + 1, y);
        revealEmpty(x - 1, y);
        revealEmpty(x, y + 1);
        revealEmpty(x, y - 1);
        
        revealEmpty(x + 1, y + 1);
        revealEmpty(x + 1, y - 1);
        revealEmpty(x - 1, y + 1);
        revealEmpty(x - 1, y - 1);
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& b, vector<int>& click) {
        int y = click[0], x = click[1];
        
        grid = b;
        
        if(grid[y][x] == 'M'){
            grid[y][x] = 'X';
        }
        
        if(grid[y][x] == 'E'){
            revealEmpty(x, y);
        }
        
        return grid;
    }
};