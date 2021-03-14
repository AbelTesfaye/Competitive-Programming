class Solution {
public:
    using a2 = array<double, 3>;
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int ret = position.size();
        
        vector< a2 > cars;
        for(int i = 0; i < position.size(); i++){
            cars.push_back({(double)position[i], (double)speed[i], (target - position[i]) / (double) speed[i]});
        }
        
        sort(cars.begin(), cars.end(), [](a2 a, a2 b){
            return a[0] < b[0];
        });
        
        for(int i = cars.size() - 2; i > -1; i--){
            a2 current = cars[i], next = cars[i + 1];
            
            if(current[2] <= next[2]){
                cars[i][2] = next[2];
                ret--;
            }     
        }
        
        
        return ret;
    }
};