#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;


int partition(vector<int> &nums, int l, int r){        
    int lastIndexSmallerThanOrEqualToLastItemInNums = l;
    for(int i = l; i <= r; i++){
        if(nums[i] <= nums[r]){
            swap(nums[i], nums[lastIndexSmallerThanOrEqualToLastItemInNums]);
            lastIndexSmallerThanOrEqualToLastItemInNums++;
        }
    }

    return lastIndexSmallerThanOrEqualToLastItemInNums - 1;
}    

int randomPartition(vector<int> &nums, int l, int r){
    int randomIndex = l + (rand() % (r - l + 1));
    swap(nums[randomIndex], nums[r]);
    
    return partition(nums, l, r);
}

int quickSelect(vector<int> &nums, int k, int l, int r){
    if(l < 0 || r > nums.size() - 1)
        return INT_MAX;
    
    int currentPartitionIndex = randomPartition(nums, l, r);
    
    int currentK =  nums.size() - currentPartitionIndex;
    if(currentK == k)
        return nums[currentPartitionIndex];
    
    if(currentK < k){
        return quickSelect(nums, k, l, currentPartitionIndex - 1);
    }
    
    return quickSelect(nums, k, currentPartitionIndex + 1, r); 
}
// Complete the findMedian function below.
int findMedian(vector<int> arr) {
    
    return quickSelect(arr, (arr.size() / 2) + 1, 0, arr.size() - 1); // because over-engineering is fun
}

int main() {
    vector<int> input = {5,2,3,1,4};

    assert(findMedian(input) == 3);

    return 0;
}