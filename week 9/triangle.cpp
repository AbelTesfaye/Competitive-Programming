class Solution {
public:    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int r = triangle.size() - 2 ; r != -1; r--){
            for(int c = 0; c < triangle[r].size(); c++){
                triangle[r][c] += min(triangle[r + 1][c], triangle[r + 1][c + 1]);
            }
        }
        
        return triangle[0][0];
    }
};