class Solution {
public:
    unordered_set<string> s;
    bool shouldTake(vector<vector<int>>& grid, int x, int y){
        if(y == -1 || y == grid.size()) return false;
        if(x == -1 || x == grid[0].size()) return false;
        if(grid[y][x] == 1) return false;
        
        string key = to_string(x) + "," + to_string(y);
        if(s.find(key) != s.end()) return false;
        
        s.insert(key);    
        
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        
        using a3 = array<int, 3>;
        queue< a3 > q;
        
        q.push({0, 0, 0});
        s.insert("0,0");
        
        while(q.size()){
            auto [x, y, m] = q.front(); q.pop();
            
            if(y == grid.size() - 1 && x == grid[0].size() - 1)
                return m + 1;
            
            if(shouldTake(grid, x + 1, y)) q.push({x + 1, y, m + 1});
            if(shouldTake(grid, x - 1, y)) q.push({x - 1, y, m + 1});
            
            if(shouldTake(grid, x, y + 1)) q.push({x, y + 1, m + 1});
            if(shouldTake(grid, x, y - 1)) q.push({x, y - 1, m + 1});
            
            if(shouldTake(grid, x + 1, y + 1)) q.push({x + 1, y + 1, m + 1});
            if(shouldTake(grid, x + 1, y - 1)) q.push({x + 1, y - 1, m + 1});
            
            if(shouldTake(grid, x - 1, y + 1)) q.push({x - 1, y + 1, m + 1});
            if(shouldTake(grid, x - 1, y - 1)) q.push({x - 1, y - 1, m + 1});
            
        }
        
        return -1;
    }
};