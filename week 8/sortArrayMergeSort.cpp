class Solution {
public:
   void mergeSort(vector<int> &arr, int l, int r){

    if(r <= l) return;
    
    int mid = (l+r) / 2;
    
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    
    vector<int> merged;
    int lOrig = l;
    
    int i = mid + 1;
    while(l <= mid && i <= r){
      if(arr[l] < arr[i]){
        merged.push_back(arr[l]);
        l++;
      } else {
        merged.push_back(arr[i]);
        i++;
      }
    }
    
    while(l <= mid){
        merged.push_back(arr[l]);
        l++;
    }
    
    while(i <= r){
        merged.push_back(arr[i]);
        i++;
    }
    
  // take the smaller of the two elements
  for(int m: merged){
    arr[lOrig++] = m;
  }

  
}
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        
        return nums;
    }
};