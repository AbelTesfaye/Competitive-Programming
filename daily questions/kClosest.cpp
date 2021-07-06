class Solution {
public:
    int findClosestValueToIndex(vector<int>& arr, int k, int x, int i){
        int l = i - 1;
        int r = i;
        
        while(r - l - 1 < k){
            if(l < 0){
                r++;
            } else if(r > arr.size() - 1){
                l--;
            }else{
                int leftDiff = x - arr[l];
                int rightDiff = arr[r] - x;
                if(leftDiff == rightDiff){
                    l--;
                }else if(leftDiff < rightDiff){
                    l--;
                }else{
                    r++;
                }
            }
        }
        
        return l + 1;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ret;
        int leftIndex = 0;
        
        if(x < arr[0]){
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        else if(x > arr[arr.size() - 1]){
            return vector<int>(arr.end() - k, arr.end());
        }
        
        int l = 0;
        int r = arr.size() - 1;

        int firstIndexGreater = 0;

        while(l <= r){
            int mid = (l + r) / 2;
            if(arr[mid] >= x){
                firstIndexGreater = mid;
            }

            if(arr[mid] > x){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        int startIndex = findClosestValueToIndex(arr, k, x, firstIndexGreater);
             
        return vector<int>(arr.begin() + startIndex, arr.begin() + startIndex + k);
    }
};