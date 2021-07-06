class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> nToF;
        
        for(int i: arr){
            nToF[i]++;
        }
        
        priority_queue< pair<int, int> > pq;
        
        for(auto &[n, f]: nToF){
            pq.push({f, n});
        }
        
        int ret = 0;
        int removed = 0;
        
        while(arr.size() && removed < (arr.size() / 2)){
            auto p = pq.top(); pq.pop();
            removed += p.first;
            ret++;
        }
        
        return ret;
    }
};