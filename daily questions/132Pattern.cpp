class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        map<int, int> ones, twos;
        
        for(int n: nums) twos[n]++;
        
        for(int n: nums){
            twos[n]--;
            
            if(twos[n] == 0) twos.erase(n);
            
            auto two = twos.lower_bound(n);
            
            if(two != twos.begin()) two--;
            
            if(two->first < n) {
                auto one = ones.lower_bound(two->first);
                
                if(one != ones.begin()) one--;
            
                if(one->first < two->first && ones.size() != 0 && twos.size() != 0) return true;
            }
            
            ones[n]++;
        }
        
        return false;
    }
};