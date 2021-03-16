class Solution {
public:
    char shift(char c, int s){
        int startChar = c - 'a';
        
        int increment = s;
        increment %= 26;
        
        int endChar = (startChar + increment) % 26;

        return 'a' + endChar;
    }
    
    string shiftingLetters(string S, vector<int>& shifts) {
        vector<int> shiftProcessed(shifts.size());
        
        shiftProcessed.back() = shifts.back();
        for(int i = shifts.size() - 2; i > -1; i--){
            shiftProcessed[i] = (shiftProcessed[i + 1] + shiftProcessed[i] + shifts[i]) % 26;
        }
        
        for(int j = 0; j < min(S.size(), shifts.size()); j++){
            int afterShift = shift(S[j], shiftProcessed[j]);
            S[j] = afterShift;
        }
        

        return S;
    }
};// wqqwlcjnkphhsyvrkdod