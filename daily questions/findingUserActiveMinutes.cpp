class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ret(k);
        unordered_map<int, unordered_set<int>> m;
        
        for(auto &l: logs) m[l[0]].insert(l[1]);
        for(auto [id, s]: m) ret[s.size() - 1]++;
        
        return ret;
    }
};