class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        auto myless = [](int n1, int n2){ return n1<n2;};
        priority_queue<int, vector<int>, decltype(myless) > pq(myless);
        
        for(int stone: stones) pq.push(stone);
        
        while(pq.size() > 1){
            int bigger = pq.top();
            pq.pop();
            int smaller = pq.top();
            pq.pop();
            
            if(bigger > smaller)
                pq.push(bigger-smaller);
        }
        if(!pq.empty())
            return pq.top();
        
        return 0;
    }
};