class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        vector<int> lefts(n), rights(n);
        
        int lastLeftSeatedIndex = -2e9;
        for(int i = 0; i < seats.size(); i++){
            
            if(seats[i] == 1){
                lastLeftSeatedIndex = i;
            }
            
            lefts[i] = lastLeftSeatedIndex; 
        }
        
        int lastRightSeatedIndex = 2e9;
        for(int i = n - 1; i != -1; i--){
            
            if(seats[i] == 1){
                lastRightSeatedIndex = i;
            }
            
            rights[i] = lastRightSeatedIndex; 
        }
        
        
        int ret = 0;
        
        for(int i = 0; i < n; i++){
            int l = i - lefts[i];
            int r = rights[i] - i;
            ret = max(ret, min(l, r));
        }
        
        return ret;
    }
};