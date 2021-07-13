class Solution {
public:
    int minOperations(int n) {
        if(n == 1) return 1;
        
        int h = n / 2;
        int ret = 0;
        
        int p = (n & 1) ? 2 : 1;
        for(int n = 0; n < h; n++){
            ret += p;
            p += 2;
        }
        
        return ret;
    }
};