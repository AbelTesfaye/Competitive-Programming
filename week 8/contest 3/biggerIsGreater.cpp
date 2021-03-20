string biggerIsGreater(string w) {
    int firstBigger = w.size() - 1;
    for(int i = w.size() - 2; i != -1; i--){
        char c = w[i], next = w[i + 1];
        if(c < next){
            int lastBigger = i;
            for(int j = i + 1; j < w.size(); j++){
                if(w[j] > c){
                    
                    lastBigger = j;
                }
            }
            
            swap(w[lastBigger], w[i]);
            
            sort(w.begin() + i + 1, w.end());
            return w;
        }
    }
return "no answer";
}