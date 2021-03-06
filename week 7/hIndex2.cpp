class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0;
        int r = citations.size() - 1;
        
        int ret = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            
            int h = citations.size() - mid;
            if(citations[mid] >= h){
                r = mid - 1;
                ret = h;
            }else{
                l = mid + 1;
            }
        }
       
        return ret;
    }
};