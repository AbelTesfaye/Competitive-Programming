class Solution {
public:
    void flood(vector<vector<int>>& image, int sr, int sc, int newColor, int startingPixelColor){
        if(sr < 0 || sc < 0 || sr == image.size() || sc == image[0].size() || image[sr][sc] != startingPixelColor ){
            return;
        }
        image[sr][sc] = newColor;
        
        flood(image, sr+1, sc, newColor, startingPixelColor);
        flood(image, sr, sc+1, newColor, startingPixelColor);
        flood(image, sr-1, sc, newColor, startingPixelColor);
        flood(image, sr, sc-1, newColor, startingPixelColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) return image;
           
        int startingPixelColor = image[sr][sc];
        
        if (newColor == startingPixelColor) return image;
            
        flood(image, sr, sc, newColor, startingPixelColor);
        
        return image;
    }
};