class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> l(n);
        int r = nums[0];
        
        for(int i = 1; i < n; i++){
            r += nums[i];
            l[i] = l[i - 1] + nums[i - 1];
        }
        
        for(int i = 0; i < n; i++){
            r -= nums[i];
            
            if(l[i] == r) return i;
        }
        
        return -1;
    }
};