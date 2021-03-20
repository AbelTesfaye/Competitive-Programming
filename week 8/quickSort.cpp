vector<int> quickSort(vector<int> arr) {
        
    swap(arr[0], arr[arr.size() - 1]);
    
    int l = 0;
    for(int r = 0; r < arr.size(); r++){
        if(arr[r] <= arr.back()){
            swap(arr[l], arr[r]);
            l++;
        }
    }
    return arr;
}