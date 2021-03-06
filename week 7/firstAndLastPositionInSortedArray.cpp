class Solution {
public:
    int findStarting(vector<int>& nums, int target){
        int ret = -1;
        
        int l = 0, r = nums.size() - 1;
        
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] >= target){
                if(nums[mid] == target){
                    ret = mid;
                }
                
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ret;
    }
    
    int findEnd(vector<int>& nums, int target, int startngLeft){
        int ret = -1;
        
        int l = startngLeft, r = nums.size() - 1;
        
        while(l <= r){
            int mid = (l + r) / 2;
            if(nums[mid] <= target){
                if(nums[mid] == target){
                    ret = mid;
                }
                
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return ret;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == -1) return {-1,-1};
        
        int startingLeft = findStarting(nums, target);
        if(startingLeft == -1) return {-1,-1};
        int targetEnd = findEnd(nums, target, startingLeft);
        
        
        return {startingLeft, targetEnd};
    }
};