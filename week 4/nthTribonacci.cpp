class Solution {
public:
    unordered_map<int, int> m = { {0,0},{1,1},{2,1} };
    
    int tribonacci(int n) {
        if(m.find(n) != m.end()) return m[n]; 
        
        return m[n] = (tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3));
    }
};