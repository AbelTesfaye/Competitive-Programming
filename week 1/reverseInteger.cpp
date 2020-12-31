class Solution {
public:
    int reverse(int x) {
        bool isNeg = x < 0;
        
        x = abs(x);
        
        long ret = 0;
        while(x != 0){
            ret *= 10;
            ret += x % 10;
            x /= 10;
            
            if(ret > INT_MAX || ret < INT_MIN) return 0;
        }
        
        if(isNeg) ret = -ret;
        
        return ret;
    }
};