class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ret = 2e9;
        using a3 = array<int, 3>;
        
        auto comp = [=](a3 p1, a3 p2){
            return p1[2] > p2[2];
        };
        
        priority_queue<a3, vector<a3>, decltype(comp)> pq(comp);
        
        for(int x = 0; x < matrix.size(); x++)
            pq.push({x,0, matrix[0][x]});
        
        while(k--){
            a3 p = pq.top(); pq.pop();
            auto [x, y, v] = p;
            ret = v;
            
            if(y + 1 < matrix.size()) 
                pq.push({x, y + 1, matrix[y + 1][x]});
        }
        
        return ret;
    }
};