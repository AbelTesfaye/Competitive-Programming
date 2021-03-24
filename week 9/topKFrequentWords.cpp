class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        using um_si = unordered_map<string, int>;
        using p_si = pair<string, int>;
        
        um_si m;
        
        for(string &s: words) m[s]++;
        
        auto comp = [=](auto &a, auto &b){
            if(a.second == b.second){
                return a.first.compare(b.first) < 0;
            }
            
            return a.second > b.second;
        };
        
        priority_queue<p_si, vector<p_si>, decltype(comp)> pq(comp);
        
        for(auto kv: m){
            pq.push(kv);
            
            if(pq.size() > k) pq.pop();
        }
        
        vector<string> ret;
        while(pq.size()){
            ret.push_back(pq.top().first); pq.pop();
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};