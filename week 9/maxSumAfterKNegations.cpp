class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int> > pq;
        
        int ret = 0;
        for(int n: A) {
            ret += n;
            pq.push(n);
        }
        
        while(K){
            int p = pq.top(); pq.pop();
            
            ret -= p;
            
            pq.push(-p);
            
            ret += -p;
            
            K--;
        }
        
        return ret;
    }
};