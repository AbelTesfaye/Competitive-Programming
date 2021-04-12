class Solution {
public:
    unordered_map<string, int> m;
    vector<string> getFolderNames(vector<string>& names) {
        
        for(string &name: names){
            
            if(m[name] == 0){
                m[name] = 1;
            } else {
                for(int i = m[name]; ;i++){
                    string newName = name + "(" + to_string(i) + ")";
                    
                    if(m[newName] == 0){
                        m[name] = i + 1;
                        m[newName] = 1;
                        name = newName;
                        break;
                    }
                }
            }            
        }
        
        return names;
    }
};