class Solution {
public:
    int partition(vector< pair<int, int> > &nums, int l, int r){
        int indexOfNextPositionForElementSmallerThanOrEqualToTheCurrentPivot = l;
        for(int i = l; i <= r; i++){
            if(nums[i].second <= nums[r].second){
                swap(nums[i], nums[indexOfNextPositionForElementSmallerThanOrEqualToTheCurrentPivot]);
                indexOfNextPositionForElementSmallerThanOrEqualToTheCurrentPivot++;
            }
        }
        
        return indexOfNextPositionForElementSmallerThanOrEqualToTheCurrentPivot - 1;
    }
    
    int randomPartition(vector< pair<int, int> > &nums, int l, int r){
        int randomIndex = l + (rand() % (r - l + 1));
        swap(nums[randomIndex], nums[r]);
        return partition(nums, l, r);
    }
    
    int quickSelect(vector< pair<int, int> > &nums, int k, int l, int r){
        if(l < 0 || r > nums.size() - 1)
            return INT_MIN;
        
        int pivotIndex = randomPartition(nums, l, r);
        
        int currentK = nums.size() - pivotIndex;
        if(currentK == k)
            return pivotIndex;
        
        if(currentK > k)
            return quickSelect(nums, k, pivotIndex + 1, r);
        
        return quickSelect(nums, k, l, pivotIndex - 1);
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int n: nums){
            m[n]++;
        }
        
        vector< pair<int, int> > uniqueNumbers(m.size());
        
        for(auto kv: m){
            uniqueNumbers.push_back({ kv.first, kv.second });
        }
        
        int indexOfK = quickSelect(uniqueNumbers, k, 0, uniqueNumbers.size() - 1);
        
        vector<int> ret;
        for(int i = indexOfK; i < uniqueNumbers.size(); i++){
            ret.push_back(uniqueNumbers[i].first);
        }
        
        return ret;
    }
};