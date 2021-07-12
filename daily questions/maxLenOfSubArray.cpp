class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector< vector<int> > dp(nums1.size() + 1, vector<int>( nums2.size() + 1 ));
        
        int ret = 0;
        
        for(int y = 1; y <= nums1.size(); y++){
            for(int x = 1; x <=nums2.size(); x++){
                                
                if(nums1[y - 1] == nums2[x - 1]){
                    dp[y][x] = dp[y - 1][x - 1] + 1;
                    ret = max(ret, dp[y][x]);
                }
            }
        }
        
        return ret;
    }
};