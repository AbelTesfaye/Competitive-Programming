class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        using pi = pair<int, int>;
        
        int ret = 0;
        
        priority_queue< pi > pq;
        
        for(int i = 1; i < heights.size(); i++){
            int p = heights[i - 1];   
            int c = heights[i];
            
            if(c <= p) {
                ret = i;
                continue;
            }
            
            // try to replace previous increments with a ladder, if imposible fail
            pq.push({c - p, i});
            bricks -= (c - p);
            
            while(bricks < 0){
                auto t = pq.top(); pq.pop();
                if(ladders > 0){
                    ladders--;
                    bricks += t.first;
                } else {
                    return i - 1;
                }
            }
            
            ret = i;
        }
        
        return ret;
    }
};