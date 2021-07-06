class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {        
        if((r * c) != (mat.size() * mat[0].size())) return mat;
        
        vector<vector<int>> ret(r, vector<int>(c));

        int y = 0, x = 0;
        for(auto &row: mat){
            for(int n: row){
                if(x == c){
                    y++;
                    x = 0;
                }  
                
                ret[y][x] = n;  
                x++;
            }
        }
        
        return ret;
    }
};