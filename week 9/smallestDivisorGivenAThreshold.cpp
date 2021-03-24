class Solution {
public:
    unordered_map<int, int> m;
    
    int sumAndDivideWithN(int n){
        int ret = 0;
        
        for(auto &[num, f]: m){
            int div = ceil(num / (double) n);
            ret += (div * f);
        }
        
        return ret;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {

        int l = 1, r = 0, ret = 0;;
        
        for(int n: nums){
            m[n]++;
            r = max(r, n);
        }
        
        while(l <= r){
            int mid = (l + r) / 2;
            if(sumAndDivideWithN(mid) <= threshold){
                ret = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ret;
    }
};