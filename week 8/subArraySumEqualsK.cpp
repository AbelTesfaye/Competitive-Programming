class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        unordered_map<int,int> prevSums;
        int sumSoFar = 0;
        
        prevSums[0]=1;
        for(int i=0; i<nums.size(); i++){
            sumSoFar+=nums[i];

            if(prevSums.find(sumSoFar - k) != prevSums.end()){
                ret+=prevSums[sumSoFar - k];
            }
            
            prevSums[sumSoFar]++;            
        }
        
        return ret;
    }
};