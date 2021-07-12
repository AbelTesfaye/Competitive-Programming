class Solution {
public:  
    int MOD = 1e9 + 7;
    
    int numDecodings(string s) {    
        if(s[0] == '0') return 0;
        
        vector<long long> dp(s.size());
        
        dp[0] = 1;
        if(s[0] == '*') dp[0] = 9;
        if(s[0] == '0' && s.size() == 1) return 0;
        
        for(int i = 1; i < s.size(); i++){
            
            if(s[i] == '*'){
                dp[i] = dp[i - 1] * 9;
            } else if(s[i] != '0'){
                dp[i] = dp[i - 1];
            }
            
            long long prev2 = 1;
            
            if(i != 1) prev2 = dp[i - 2];
            
            if(s[i] == '0' && (s[i - 1] != '1'  && s[i - 1] != '2' && s[i - 1] != '*')) return 0;
            
            if(s[i - 1] == '*'){
                if(s[i] >= '0' && s[i] <= '6'){
                    dp[i] += prev2 * 2;
                } else if(s[i] == '*'){
                    dp[i] += prev2 * 15;
                } else {
                    dp[i] += prev2;
                } 
            }
            
            if(s[i - 1] == '1'){
                if(s[i] == '*'){
                    dp[i] += prev2 * 9;
                } else {
                    dp[i] += prev2;
                }
            }
            
            if(s[i - 1] == '2'){
                if(s[i] == '*'){
                    dp[i] += prev2 * 6;
                } else if(s[i] >= '0' && s[i] <= '6') {
                    dp[i] += prev2;
                }
            }
            
            dp[i] = dp[i] % MOD;
        }
        
        return dp.back();
    }
};