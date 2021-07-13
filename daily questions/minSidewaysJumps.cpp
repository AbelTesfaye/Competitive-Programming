class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector< vector<int> > dp( obstacles.size(), vector<int>(3) );
        
        for(int i = dp.size() - 2; i != -1; i--){
            for(int l: {0, 1, 2}){
                dp[i][l] = dp[i + 1][l];
                
                if(obstacles[i] == (l + 1)) dp[i][l] = 2e9;
            }
            
            for(int l: {0, 1, 2}){
                for(int j: {0, 1, 2}){
                    if(j == l || obstacles[i] == (l + 1)) continue;

                    dp[i][l] = min(dp[i][l], dp[i][j] + 1);
                }
            }
            
        }
        
        return dp[0][1];
    }
};