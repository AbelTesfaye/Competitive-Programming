class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s = nums.size();
        
        vector<int> l(s), r(s), ret(s);
        
        for(int i = 0; i < nums.size(); i++){
            
            if(i == 0){
                l[i] = 1; 
            } else {
                int n = nums[i - 1];
                l[i] = n * l[i-1];
            }
        }
        
        for(int i = nums.size() - 1; i != -1; i--){            
            if(i == nums.size() - 1){
                r[i] = 1;
            } else {
                int n = nums[i + 1];
                r[i] = n * r[i + 1];
            }
        }
        
        for(int i = 0; i <nums.size(); i++){
//             if(i - 1 == -1){
//                 ret[i] = r[i + 1];
//                 continue;
//             }
            
//             if(i + 1 == nums.size()){
//                 ret[i] = l[i];
//                 continue;
//             }
            
            ret[i] = l[i] * r[i];
        }
        
        return ret;
    }
};