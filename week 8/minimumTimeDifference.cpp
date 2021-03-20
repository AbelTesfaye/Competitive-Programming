class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        
        int ret = INT_MAX;
                
        for(string &s: timePoints){
            int h = stoi(s.substr(0, 2)) * 60;
            int min = stoi(s.substr(3, 2));
                        
            int mins = h + min;
            v.push_back(mins);
        }
                
        sort(v.begin(), v.end());
        
        for(int i = 1; i < v.size(); i++){
            int diff1 = v[i] - v[i-1];
            int diff2 = (1440 - v[i]) + v[i-1];
            
            ret = min(ret, diff1);
            ret = min(ret, diff2);
        }
        
        int diff2 = (1440 - v.back()) + v.front();

        ret = min(ret, abs(diff2));
        
        return ret;
    }
};