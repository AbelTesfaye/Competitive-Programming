class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int sellDay = prices.size() - 1;
        
        for(int i = prices.size() - 2; i != -1; i--){
            int profitBuyToday = prices[i] - prices[sellDay];
            
            if(prices[i] > prices[sellDay]){
                sellDay = i;
            }
            
            if(prices[i] < prices[sellDay]){
                ret += prices[sellDay] - prices[i];
                sellDay = i;
            }
        }
        
        return ret;
    }
};