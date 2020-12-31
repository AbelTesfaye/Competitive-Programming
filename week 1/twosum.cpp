class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hm;
        
        for(int i=0; i< nums.size() ;i++){
            int n = nums[i];
            int complement = target - n;
            
            if( hm.find(complement) != hm.end() ){
                return  {hm[complement], i};
            }
            
            hm[n] = i; 
        }
        
        return  {-1,-1};
        
    }
};