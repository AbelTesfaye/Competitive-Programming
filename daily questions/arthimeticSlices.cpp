class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        
        int ret = 0;
        int l = 0, r = -1;
        while(l < nums.size()){
            r = l + 2;
            
            while(r < nums.size() && (nums[r] - nums[r - 1]) == (nums[l + 1] - nums[l])){
                r++;
            }
            
            int pr = r - 1;
            int ppr = pr;
            int s = pr - l + 1;
            while(s >= 3){
                int nr = pr - ppr;
                
                ret += 1 + nr;
                
                ppr--;
                s--;
                l = pr - 1;
            }
            
            l++;
        }
        
        return ret;
    }
};