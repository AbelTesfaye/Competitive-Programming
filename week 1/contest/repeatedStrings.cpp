long repeatedString(string s, long n) {
    int firstNCount = 0;
    for(int i =0; i < min(n, (long int)s.size()); i++){
        if(s[i] == 'a') firstNCount++;
    }
    
    if(n <= (int)s.size()){
        return firstNCount;
    }
    
    long fullSegmentCounts = n / s.size();
    
    int fullNCountInS = 0;
    for(int i =0; i < (int)s.size(); i++){
        if(s[i] == 'a') fullNCountInS++;
    }
    
    long confirmed = fullNCountInS * fullSegmentCounts;
    
    int nc = 0;
    for(long i = 0; i < (n - (s.size() * fullSegmentCounts));i++){
        if(s[i] == 'a') nc++;
    }
    
    return confirmed + nc;
}