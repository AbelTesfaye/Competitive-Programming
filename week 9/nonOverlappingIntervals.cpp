class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        
        int longestNonOverlap = 0;
        
        int lastEnd = -1;
        
        for(auto &i: intervals){
            int st = i[0], end = i[1];
            if(st >= lastEnd){
                longestNonOverlap++;
                lastEnd = end;
            }
            
        }
        
        return intervals.size() - longestNonOverlap;
    }
};