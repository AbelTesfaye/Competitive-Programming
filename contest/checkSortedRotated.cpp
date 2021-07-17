class Solution {
public:
    bool isNonDec(vector<int> &nums, int startI){
        
        int prev = -2e9;
        for(int i = startI; i < nums.size(); i++){
            int n = nums[i];
            if(n < prev) return false;
            prev = n;
        }
        
        return true;
    }
    
    bool check(vector<int>& nums) {
        
        if(isNonDec(nums, 0)) return true;
        
        int prev = -2e9;
        for(int i = 0; i < nums.size(); i++){
            int n = nums[i];
            
            if(n < prev){             
                return nums.back() <= nums[0] && isNonDec(nums, i);
            }
            
            prev = n;
        }
        
        return true;
    }
};
