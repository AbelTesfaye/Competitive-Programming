class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> soldierCount(mat.size()), weakness(mat.size());
        
        for(int y = 0; y < mat.size(); y++){
            for(int x = 0; x < mat[0].size(); x++){
                if(mat[y][x] == 0) break;
                
                soldierCount[y]++;
            }
        }
        
        for(int y = 0; y < mat.size(); y++){
            for(int ny = 0; ny < mat.size(); ny++){
                if(y == ny) continue;
                
                if(soldierCount[y] < soldierCount[ny]){
                    weakness[y]++;
                }
                
                if(soldierCount[y] == soldierCount[ny] && y < ny){
                    weakness[y]++;
                }
            }
        }
        
        for(int i = 0; i < mat.size(); i++){
            // weakness[i]--;
            // cout<<"weakness of: "<<i<<" is "<<weakness[i]<<endl;
            // cout<<"soldierCount of: "<<i<<" is "<<soldierCount[i]<<endl;
        }
        
        using pi = pair<int, int >;
        
        priority_queue< pi > pq;
        
        for(int i = 0; i < mat.size(); i++){            
            pq.push({weakness[i],i});
            
        }
        
        vector<int> ret;
        while(k){
            auto p = pq.top(); pq.pop();
            ret.push_back(p.second);
            k--;
        }
        
        return ret;
    }
};