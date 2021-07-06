class MapSum {
public:
    unordered_map<string, int>m,kv;
    /** Initialize your data structure here. */
    MapSum() {

    }
    
    void insert(string key, int val) {
        int diff = val;
        if(kv.find(key) != kv.end()) diff = (val - kv[key]);
        
        string str = "";
        for(char c: key){
            str += c;
            
            m[str]+= diff;
        }
        kv[key] = val;
    }
    
    int sum(string prefix) {
        return m[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */