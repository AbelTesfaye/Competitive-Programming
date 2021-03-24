class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        vector<int> lModified, rModified;
        
        lModified.push_back(nums[0]);
        rModified.push_back(nums[0]);
        bool isModified = false;
        
        for(int i = 1; i < nums.size(); i++){
            int p = nums[i - 1], c = nums[i];
            if(c < p){
                if(isModified) return false;
                lModified.back() = c;
                lModified.push_back(c);
                
                rModified.push_back(rModified.back());
                isModified = true;
            } else {
                lModified.push_back(c);
                rModified.push_back(c);
            }
        }
        
        bool isLModBad = false, isRModBad = false;
        for(int i = 1; i < nums.size(); i++){
            isLModBad |= lModified[i] < lModified[i-1];
            isRModBad |= rModified[i] < rModified[i-1];
        }
        
        if(isLModBad && isRModBad) return false;
        
        return true;
    }
};