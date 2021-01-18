class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ret = 0;
        
        for(string &s: logs){
            if(s == "../") ret = max(ret - 1, 0);
            else if(s == "./");
            else ret++;
        }
        
        return ret;
    }
};
