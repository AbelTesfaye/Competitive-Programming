string W = "WRONG PASSWORD";

string dfs(unordered_map<string, string> &m, vector<string> &passwords, string &loginAttempt, string &currentPassword, vector<string> currentWords){
    
    if(m[currentPassword] == W) return W;
    
    for(string &p: passwords){
        if(loginAttempt.find(p, currentPassword.size()) != currentPassword.size()) continue;
        
        cout<<"currentPassword: "<<currentPassword<<endl;
        
        currentPassword += p;
        currentWords.push_back(p);
        
        if(currentPassword.size() == loginAttempt.size()) {
            string spaced = "";

            for(string &w: currentWords){
                if(spaced.empty()){
                    spaced = w;
                    continue;
                }

                spaced += " " + w;
            }

            return spaced;
        }
        
        string ret = dfs(m, passwords, loginAttempt, currentPassword, currentWords);
        
        if(ret != W) return ret;
        
        currentPassword.erase(currentPassword.end() - p.size() , currentPassword.end());
        currentWords.pop_back();
    }
        
    return m[currentPassword] = W;
}
string passwordCracker(vector<string> passwords, string loginAttempt) {
    cout<<"loginAttempt: "<<loginAttempt<<endl;
    
    string currentPassword = "";
    vector<string> currentWords;
    unordered_map<string, string> m;
    
    return dfs(m, passwords, loginAttempt, currentPassword, currentWords);
}