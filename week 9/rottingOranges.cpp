class Solution {
public:
    unordered_set<string> s;
    bool isNotVisited(int x, int y){
        string key = to_string(x) +"," + to_string(y);
        
        return s.find(key) == s.end();     
    }
    
    bool isValid(vector<vector<int>>& grid, int x, int y){
        if(y == -1 || y == grid.size()) return false;
        if(x == -1 || x == grid[0].size()) return false;
        if(grid[y][x] == 0) return false;
        
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        using a2 = array<int, 2>;
        
        queue< a2 > q;
        
        int totalOranges = 0;
        
        for(int y = 0; y < grid.size(); y++){
            for(int x = 0; x < grid[0].size(); x++){
                if(grid[y][x] > 0) totalOranges++;
                
                if(grid[y][x] != 2) continue;
                
                q.push({y, x});
                
                string key = to_string(x) +"," + to_string(y);
                s.insert(key);
            }
        }
        
        int ret = 0;
        while(q.size()){
            int n = q.size();
            
            while(n){
                auto [prevY, prevX] = q.front(); q.pop();
                
                if(isValid(grid, prevX + 1, prevY) && isNotVisited(prevX + 1, prevY)){
                    q.push({prevY, prevX + 1});
                    
                    string key = to_string(prevX + 1) +"," + to_string(prevY);
                    s.insert(key);
                }
                
                if(isValid(grid, prevX - 1, prevY) && isNotVisited(prevX - 1, prevY)){
                    q.push({prevY, prevX - 1});
                    
                    string key = to_string(prevX - 1) +"," + to_string(prevY);
                    s.insert(key);
                }
                
                if(isValid(grid, prevX, prevY + 1) && isNotVisited(prevX, prevY + 1)){
                    q.push({prevY + 1, prevX});
                    
                    string key = to_string(prevX) +"," + to_string(prevY + 1);
                    s.insert(key);
                }
                
                if(isValid(grid, prevX, prevY - 1) && isNotVisited(prevX, prevY - 1)){
                    q.push({prevY - 1, prevX});
                    
                    string key = to_string(prevX) +"," + to_string(prevY - 1);
                    s.insert(key);
                }
                
                n--;
            }
            
            ret++;
        }
        
        if(s.size() != totalOranges) return -1;
        
        if(totalOranges == 0) return 0;
        
        return ret - 1;
    }
};