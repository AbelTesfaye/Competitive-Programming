class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int currentN = 1;

        vector<string> ret;
        for(int t: target){
            while(currentN != t){
                ret.push_back("Push");    
                ret.push_back("Pop");
                currentN++;
            }
                
            ret.push_back("Push");
            currentN++;
        }
        
        return ret;
    }
};