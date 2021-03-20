class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int M = 1e9 + 7;
        long long int ret = 0;
        
        vector<int> x, y;
        
        for(auto r: rectangles){
            x.push_back(r[0]);
            x.push_back(r[2]);
            
            y.push_back(r[1]);
            y.push_back(r[3]);
        }
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        unordered_map<int, int> ym, xm;
        
        for(int i = 0; i < x.size(); i++){
            xm[x[i]] = i;  
        }
        
        for(int i = 0; i < y.size(); i++){
            ym[y[i]] = i;  
        }
        
        vector< vector<int> > m(y.size(), vector<int> (x.size()));
                
        for(auto r: rectangles){
            for(int y = ym[r[1]]; y < ym[r[3]]; y++){
                for(int x = xm[r[0]]; x < xm[r[2]]; x++){
                   m[y][x] = true;
                }
            }
        }
        
        for(int yy = 1; yy < m.size(); yy++){
            for(int xx = 1; xx < m[0].size(); xx++){
                if(!m[yy - 1][xx - 1]) continue;
                
                int xDiff = x[xx] - x[xx - 1], yDiff = y[yy] - y[yy - 1];
                
                ret = (ret + (xDiff * (long long)yDiff) % M) % M;
            }
        }
        
        return ret % M;
    }
};