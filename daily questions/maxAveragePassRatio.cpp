class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto f = [](auto &p1, auto &p2){
            double r1 = ((p1.second + 1) / (double)(p1.first + 1)) - (p1.second / (double)p1.first);
            double r2 = ((p2.second + 1) / (double)(p2.first + 1)) - (p2.second / (double)p2.first);
            
            return r1 < r2;
        };
        priority_queue< pair<int, int>, vector< pair<int, int> >, __decltype(f)> pq(f);
        
        for(auto &c: classes) pq.push({c[1], c[0]});
        
        while(extraStudents--){
            auto p = pq.top(); pq.pop();
            
            pq.push({p.first + 1, p.second + 1});
        }
        
        double ret = 0;
        while(pq.size()){
            auto p = pq.top(); pq.pop();
            ret += (p.second / (double) p.first);
        }
        
        ret /= classes.size();
        
        return ret;
    }
};