class Solution {
public:   
    unordered_map<int,  vector<int> > row;
    unordered_map<int,  vector<int> > col;

    unordered_set<string> s;

    int dfs(int r, int c, int depth){
        string key = to_string(r) + "," + to_string(c);
        
        if(s.find(key) != s.end()) return 0;
        s.insert(key);

        for(int col: row[r]){
            depth = max(depth, dfs(r, col, depth + 1));
        }
        
        for(int row: col[c]){
            depth = max(depth, dfs(row, c, depth + 1));
        }
                
        return depth;
    }

    int removeStones(vector<vector<int>>& stones) {
        if(stones.size() == 0) return 0;
        if(stones.size() == 1) return 0;
        
        int ret = 0;
        
        for(auto stone: stones){
            row[stone[0]].push_back(stone[1]);
            col[stone[1]].push_back(stone[0]);
        }
        
        for(auto kv: row){
            int r = kv.first;
            for(auto c: kv.second){     
                int countsStartingFromHere = max(0, dfs(r,c, 1) - 1);
                ret += countsStartingFromHere;
            }
        }
                
        return ret;
    }
    
    /*
[[3,2],[3,1],[4,4],[1,1],[0,2],[4,0]]
[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
[[0,0],[0,2],[1,1],[2,0],[2,2]]
[[0,0],[0,1],[1,0],[1,1],[2,1],[2,2],[3,2],[3,3],[3,4],[4,3],[4,4]]
*/
    
};