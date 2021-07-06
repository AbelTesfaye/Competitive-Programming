class Solution {
public:
    unordered_map<string, int> m;
    
    int dfs(vector<vector<int>>& matrix, vector<vector<bool>>& vis, int currentSequenceCount, int prevNum, int x, int y){
        string key = to_string(x) + "," + to_string(y);
        if(
            y == -1 || y == matrix.size() || x == -1 || x == matrix[0].size() ||
           matrix[y][x] <= prevNum || vis[y][x]
        ) return 0;
        
        if(m[key] != 0) return m[key];
        
        vis[y][x] = true;
        
        int ret = dfs(matrix, vis, currentSequenceCount + 1, matrix[y][x], x + 1, y);
        ret = max(ret, dfs(matrix, vis, currentSequenceCount + 1, matrix[y][x], x - 1, y));
        ret = max(ret, dfs(matrix, vis, currentSequenceCount + 1, matrix[y][x], x, y + 1));
        ret = max(ret, dfs(matrix, vis, currentSequenceCount + 1, matrix[y][x], x, y - 1));
        
        vis[y][x] = false;
        
        return m[key] = ret + 1;
    }
        
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        
        vector< vector<bool> > vis( matrix.size(), vector<bool>(matrix[0].size()) );
        
        int ma = INT_MIN;
        for(int y = 0; y < matrix.size(); y++){
            for(int x = 0; x < matrix[0].size(); x++){
                ma = max(ma, dfs(matrix, vis, 0, INT_MIN, x, y));
            }
        }
        
        return ma;    
    }
};