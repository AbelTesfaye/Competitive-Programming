class Solution {
public:
    bool canMove(vector<vector<int>>& grid, int x1, int y1, int x2, int y2){
        int n = grid.size();
        
        if(x1 == n || x1 == -1) return false;
        if(x2 == n || x2 == -1) return false;
        if(y1 == n || y1 == -1) return false;
        if(y2 == n || y2 == -1) return false;
        
        if(grid[y1][x1] == 1 || grid[y2][x2] == 1) return false;
                
        return true;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        
        using a6 = array<int, 6>;
        
        queue<a6> q;
        unordered_set<string> vis;
        
        q.push({0,0, 1,0, 0, 0});
        
        while(!q.empty()){
            auto [tx, ty, hx, hy, r, m] = q.front(); q.pop();
            
            if(tx == n - 2 && ty == n - 1 && hx == n - 1 && hy == n - 1) {
                return m;
            }
            
            string key = to_string(tx)+","+to_string(ty)+","
                +to_string(hx)+","+to_string(hy)+","+to_string(r);
            
            if(vis.find(key) != vis.end()) continue;
            
            vis.insert(key);
            
            // attempt move down
            if(canMove(grid, tx, ty + 1, hx, hy + 1)){
                q.push({tx, ty + 1, hx, hy + 1, r, m + 1});
            }
            // attempt move right
            if(canMove(grid, tx + 1, ty, hx + 1, hy)){
                q.push({tx + 1, ty, hx + 1, hy, r, m + 1});
            }
            
            // attempt clockwise
            if(canMove(grid, tx, ty, tx, ty + 1) && canMove(grid, tx + 1, ty, tx + 1, ty + 1)){
                q.push({tx, ty, tx, ty + 1, 1, m + 1});
            }
            // attempt anti-clockwise
            if(canMove(grid, tx, ty, tx + 1, ty) && canMove(grid, tx + 1, ty, tx + 1, ty + 1)){
                q.push({tx, ty, tx + 1, ty, 0, m + 1});
            }
            
        }
        
        return -1;
    }
};