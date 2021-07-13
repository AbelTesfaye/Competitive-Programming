class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ret = 0;
        
        int l = 0, r = nums.size() - 1;
        
        while(l <= r){
            
            int mid = (l + r) / 2;
            
            if(l == r) {
                if(nums[mid] > nums[ret]) ret = mid;

                return ret;
            }
            
            if(nums[mid] > nums[mid + 1]){
                if(nums[mid] > nums[ret]) ret = mid;
                
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ret;
    }
};