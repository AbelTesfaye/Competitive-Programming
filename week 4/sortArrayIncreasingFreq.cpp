class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(int n: nums) m[n]++;
        
        sort(nums.begin(), nums.end(), [&](int a, int b){
            
            if(m[a] == m[b]){
                return a > b;
            }
            
            return m[a] < m[b];
        });
        
        return nums;
    }
};