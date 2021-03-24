class Solution {
public:
    unordered_map<int, int> m;
    
    int dfs(vector<int> &arr, int d, int currentIndex, int prevHeight){
        if(currentIndex < 0 || currentIndex >= arr.size() || arr[currentIndex] >= prevHeight) return 0;
        if(m.find(currentIndex) != m.end()) return m[currentIndex];
        
        int ma = 0;
        for(int i = currentIndex - 1; i >= max(0, currentIndex - d); i--){
            if(arr[i] >= arr[currentIndex]) break;
            
            int n = dfs(arr, d, i, arr[currentIndex]);
            ma = max(ma, n);
        }
        
        for(int i = currentIndex + 1; i <= min((int) arr.size() - 1, currentIndex + d); i++){
            if(arr[i] >= arr[currentIndex]) break;
            
            int n = dfs(arr, d, i, arr[currentIndex]);
            ma = max(ma, n);
        }
        
        return m[currentIndex] = ma + 1;
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int ret = 0;
        
        for(int i = 0; i < arr.size(); i++){
            int a = dfs(arr, d, i, 2e9);
            ret = max(ret, a);
            
            // cout<<"from val: "<<arr[i]<<" got to: "<<a<<endl;
        }
        
        return ret;
    }
};