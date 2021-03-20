
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        string file = "";
        stringstream ss(path);
        while(getline(ss, file, '/')){
            if(file == "." || file == ""){ }
            else if(file == ".." ){
                if(v.size() != 0) v.pop_back();
            }
            else {
                v.push_back(file);
            }
        }

        path = "/";
        for(string s: v){
            path += s + "/";
        }

        if(path.size() != 1){
            path.pop_back();
        }

        return path;
    }
};