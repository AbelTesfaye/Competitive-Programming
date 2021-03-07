class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        using sum_pair = pair< int, vector<int> >;
        priority_queue< sum_pair > pq;
        vector< vector<int> > ret;
        
        while(nums1.size() > k) nums1.pop_back();
        while(nums2.size() > k) nums2.pop_back();
        
        for(int n1: nums1){
            for(int n2: nums2){
                sum_pair currentPair = {n1 + n2, {n1, n2}};
                
                pq.push(currentPair);
                
                if(pq.size() > k) 
                    pq.pop();
            }
        }
        
        while(pq.size()) {
            auto p = pq.top(); pq.pop();
            ret.push_back(p.second);
        }
        
        return ret;
    }
};