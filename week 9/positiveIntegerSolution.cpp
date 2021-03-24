/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector< vector<int> > ret;
    
    void findY(int x, int z, CustomFunction& customfunction){
        
        int l = 1, r = 1000;
        while(l <= r){
            int y = (l + r) / 2;
            int v = customfunction.f(x,y);
            
            if(v == z){
                ret.push_back({x, y});
                return;
            }
            
            if(v < z){
                l = y + 1;
            } else {
                r = y - 1;
            }
        }
    }
    
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        for(int x = 1; x <= 1000; x++){
            findY(x, z, customfunction);
        }
        
        return ret;
    }
};