class Solution {
public:
    unordered_map<char, int> m;

    string customSortString(string order, string str) {
        
        for(int i = 0; i < order.size(); i++) m[order[i]] = i;
                
        sort(str.begin(), str.end(), [=](char c1, char c2){
            return m[c1] < m[c2];
        });
        
        return str;
    }
};