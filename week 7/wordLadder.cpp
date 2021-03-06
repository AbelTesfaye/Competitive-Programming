class Solution {
public:    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> unvisited(wordList.begin(), wordList.end());
        queue<pair<string, int> > q;
        
        q.push({beginWord, 1});
                
        while(!q.empty()){
            auto currentWord = q.front(); q.pop();
            
            for(int i = 0; i < currentWord.first.size(); i++){
                for(char a = 'a'; a <= 'z'; a++){
                    char prev = currentWord.first[i];
                    currentWord.first[i] = a;
                    if(unvisited.find(currentWord.first) != unvisited.end()){
                        if(endWord == currentWord.first) return currentWord.second + 1;
                
                        q.push({currentWord.first, currentWord.second + 1});
                        unvisited.erase(currentWord.first);

                    }
                    currentWord.first[i] = prev;

                }

            }
        }
        
        return 0;
    }
};