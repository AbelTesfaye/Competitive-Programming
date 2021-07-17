
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ret = 0;
        
        array<int, 3> arr = {a, b, c};
        
        sort(arr.begin(), arr.end());
        
        while(arr[1] != 0){
            
            arr[1]--;
            arr[2]--;
            
            sort(arr.begin(), arr.end());

            ret++;
        }
        
        return ret;
    }
};