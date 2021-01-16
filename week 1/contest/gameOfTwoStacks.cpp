int twoStacks(int x, vector<int> n1, vector<int> n2) {
    /*
     * Write your code here.
     */
    vector<int> p1, p2;

    int p1Sum = 0;
    for(int i = 0; i < n1.size(); i++){
      if(p1Sum + n1[i] <= x){
        p1Sum += n1[i];
        p1.push_back(p1Sum);
      } else {
        break;
      }  
    }

    int p2Sum = 0;
    for(int i = 0; i < n2.size(); i++){
      if(p2Sum + n2[i] <= x){
        p2Sum += n2[i];
        p2.push_back(p2Sum);
      } else {
        break;
      }  
    }
    
    int ret = 0;
    for(int i = 0; i < p1.size(); i++){
        int numsTaken = i + 1;
        int complement = x - p1[i];
        auto it = upper_bound(p2.begin(), p2.end(), complement);
        
        if(it != p2.begin()){
            it--;
            numsTaken += it - p2.begin() + 1;
        }
        
        ret = max(ret, numsTaken);
    }
    
    for(int i = 0; i < p2.size(); i++){
        int numsTaken = i + 1;
        int complement = x - p2[i];
        auto it = upper_bound(p1.begin(), p1.end(), complement);
        
        if(it != p1.begin()){
            it--;
            numsTaken += it - p1.begin() + 1;
        }
        ret = max(ret, numsTaken);
    }
    
    return ret;

}