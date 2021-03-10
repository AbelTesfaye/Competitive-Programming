class Solution {
public:
    /*
    "abcd"
    "bcdf"
    
"abcd"
"cdef"
3
    */
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0, r = 0;

        int ret = 0;
        int currentCost = 0;
        while(r < s.size()){
          currentCost += abs(s[r] - t[r]);

          while(l <= r && currentCost > maxCost) {
            // remove element at l till valid
            currentCost -= abs(s[l] - t[l]);
            l++;
          }
        
        
          ret = max(ret, r - l + 1);

          r++;
        }

        return ret;
    }
};