
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ret = "";
        reverse(word1.begin(), word1.end());
        reverse(word2.begin(), word2.end());
        
        while(word1.size() && word2.size()){
            bool w1 = false;

            if(word1.back() == word2.back()){
                
                int w1i = word1.size() - 1, w2i = word2.size() - 1;
                while(w1i != -1 && w2i != -1 && word2[w2i] == word1[w1i]){
                    w1i--;
                    w2i--;
                }
                
                if(w1i == -1 && w2i == -1) w1 = true;
                else if(w1i == -1 && w2i != -1) w1 = false;
                else if(w2i == -1 && w1i != -1) w1 = true;
                else if(word1[w1i] > word2[w2i]) w1 = true;
                else w1 = false;
            } 
            
            if(w1 || word1.back() > word2.back()){
                ret += word1.back(); word1.pop_back();
            } else {
                ret += word2.back(); word2.pop_back();
            }
        }
        
        reverse(word1.begin(), word1.end());
        reverse(word2.begin(), word2.end());
        
        ret += word1;
        ret += word2;
        
        return ret;
    }
};
