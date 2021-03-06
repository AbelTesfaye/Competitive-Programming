class Solution {
public:
    bool isNextToWater(vector< vector<int> > &arr, int x, int y){
        
        if(x - 1 > -1 && arr[y][x - 1] == 0) return true;
        if(x + 1 < arr[0].size() && arr[y][x + 1] == 0) return true;

        if(y - 1 > -1 && arr[y - 1][x] == 0) return true;
        if(y + 1 < arr.size() && arr[y + 1][x] == 0) return true;
        
        return false;
    }
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        
        for(int y = 0; y < isWater.size(); y++){
            for(int x = 0; x < isWater[0].size(); x++){
                isWater[y][x] = !isWater[y][x];
            }
        }
        
        queue< array<int, 3> > q;
        for(int y = 0; y < isWater.size(); y++){
            for(int x = 0; x < isWater[0].size(); x++){
                if(isWater[y][x] == 0) continue;
                
                if(isNextToWater(isWater, x, y)){
                    q.push({0, x, y});
                }
            }
        }
        
        while(q.size()){
            int currentLayerItems = q.size();
            while(currentLayerItems){
                auto [prevHeight, x, y] = q.front(); q.pop();
                currentLayerItems--;
                
                int h = prevHeight + 1;
                
                if(isWater[y][x] < 0){
                     continue;
                }
                   
                
                isWater[y][x] = -h;
                
                if(x - 1 > -1 && isWater[y][x - 1] == 1) q.push({h, x - 1, y});
                if(x + 1 < isWater[0].size() && isWater[y][x + 1] == 1) q.push({h, x + 1, y});

                if(y - 1 > -1 && isWater[y - 1][x] == 1) q.push({h, x, y - 1});
                if(y + 1 < isWater.size() && isWater[y + 1][x] == 1) q.push({h, x, y + 1});
                 
            }
        }
        
        for(int y = 0; y < isWater.size(); y++){
            for(int x = 0; x < isWater[0].size(); x++){
                isWater[y][x] = abs(isWater[y][x]);
            }
        }
        
        return isWater;
    }
};