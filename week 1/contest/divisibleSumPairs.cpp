// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar) {
    unordered_set<int> s;
    int ret = 0;

    for(int i = 0; i < (int)ar.size(); i++){
        for(int j = 0; j < i; j++){
            if((ar[i] + ar[j]) % k == 0){
                ret++;
            }
        }
    }
    
    return ret;
}