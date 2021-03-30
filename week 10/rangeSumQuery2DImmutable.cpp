class NumMatrix {
public:
    vector<vector<int>> dp;
    
    NumMatrix(vector<vector<int>>& matrix) {
        dp = matrix;
        
        for(int y = 0; y < matrix.size(); y++){
            for(int x = 0; x < matrix[0].size(); x++){
                if(x == 0 && y == 0) continue;
                
                if(x-1 == -1){
                    dp[y][x] += dp[y-1][x];
                } else if (y-1 == -1){
                    dp[y][x] += dp[y][x-1];
                } else {
                    dp[y][x] +=  dp[y-1][x] + dp[y][x-1] - dp[y-1][x-1];
                }
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = dp[row2][col2];
        int lBorder = col1 - 1;
        int tBorder = row1 - 1;
        
        int top = 0;
        int left = 0;
        int overlap = 0;
        
        if(tBorder != -1)
            top = dp[tBorder][col2];
        
        if(lBorder != -1)
            left = dp[row2][lBorder];
        
        if(lBorder != -1 && tBorder != -1)
            overlap = dp[tBorder][lBorder];
        
        return total - top - left + overlap;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */