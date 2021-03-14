class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.size() == 0) return 0;
        
        sort(tokens.begin(), tokens.end());
        
        int ret = 0, score = 0;
        int l = 0, r = tokens.size() - 1;
        
        bool shouldAttemptATrade = true;
        
        while(shouldAttemptATrade){
            shouldAttemptATrade = false;
            
            // try to trade smallest token to get 1 score
            while(l < tokens.size() && P - tokens[l] >= 0 && l <= r){
                shouldAttemptATrade = true;
                
                P -= tokens[l];
                score++;
                l++;
            }
            
            ret = max(ret, score);
            
            // try to trade score to get more token
            while(r > -1 && score > 0 && r > l && P - tokens[l] < 0){
                shouldAttemptATrade = true;
                
                P += tokens[r];
                score--;
                r--;
            }
        }
        
        return ret;
    }
};