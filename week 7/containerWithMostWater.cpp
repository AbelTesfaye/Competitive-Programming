class Solution {
public:
    int maxArea(vector<int>& height) {
            int l = 0, r = height.size() - 1;
            int maxArea = 0;
            int currentArea = 0;
        
            while(l < r){
                
                if(height[l] < height[r]){
                    currentArea = (height[l]) * (r-l);
                    l++;
                }else{     
                    currentArea = (height[r]) * (r-l);
                    r--;
                }
                
                maxArea = max(maxArea, currentArea);
            }
        
        return maxArea;
    }
};