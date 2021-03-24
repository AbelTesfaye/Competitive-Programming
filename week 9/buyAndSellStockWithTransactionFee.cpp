class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp(prices.size());
        int ret = 0;
        
        using pi = pair<int, int>;
        
        priority_queue< pi > pq;
        
        pq.push({-prices[0] ,0});
        
        for(int i = 1; i < prices.size(); i++){
            auto p = pq.top();
            
            dp[i] = max({dp[i], prices[i] - fee + p.first, dp[i - 1]});
                
            int c = -prices[i] + dp[i - 1];
            pq.push({c, i});
            
            ret = max(ret, dp[i]);
        }
        
//         for(int i = 1; i < prices.size(); i++){
//             for(int j = 0; j < i; j++){
//                 int prev = 0;
                
//                 if(j != 0) prev = dp[j - 1];
                
//                 dp[i] = max({dp[i], prices[i] - prices[j] - fee + prev, dp[i - 1]});
                
//                 ret = max(ret, dp[i]);
//             }
//         }
        
        return ret;
    }
};