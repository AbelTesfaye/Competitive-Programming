
// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    
    long ret = 0; 
    
    for(int i = 0; i < h.size(); i++){
        int li = -1, ri = h.size();
        
        for(int l = i -1; l != -1; l--){
            if(h[l] < h[i]) {
                li = l;
                break;
            }
        }
        
        for(int r = i +1; r != h.size() ; r++){
            if(h[r] < h[i]) {
                ri = r;
                break;
            }
        }
        
        ret = max((long)h[i] * (ri - li - 1), ret);
        
    }
    
    return ret;
}