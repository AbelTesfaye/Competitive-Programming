class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ret = 1;
                
        for(int r = 1; r < nums.size(); r++){
            for(int l = 0; l < r; l++){
                if(nums[r] <= nums[l]) continue;
                
                dp[r] = max(dp[r], dp[l] + 1);
                ret = max(ret, dp[r]);
            }
            
        }
        
        return ret;
    }
};