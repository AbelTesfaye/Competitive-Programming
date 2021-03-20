class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, ret = 0;
        string maxStr = "";
        unordered_map<char, int> m;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];

            if(m.find(c) != m.end()) {
                l = max(m[c] + 1, l);
            }

            m[c] = r;

            ret = max(ret, r - l + 1);
        }

        return ret;
    }
};