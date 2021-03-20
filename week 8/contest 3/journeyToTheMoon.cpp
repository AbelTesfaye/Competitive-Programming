int C = 0;
unordered_map<int, vector<int>> m;
unordered_map<int, int> country;
unordered_map<int, int> countryCount;


unordered_set<int> s;

void dfs(int currentPerson){
    if(s.find(currentPerson) != s.end()) return;
    
    s.insert(currentPerson);
    
    country[currentPerson] = C;
    countryCount[C]++;
    for(int adj: m[currentPerson]){
        dfs(adj);
    }
    
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    
    for(auto a: astronaut){
        m[a[0]].push_back(a[1]);
        m[a[1]].push_back(a[0]);
    }
    
    for(int i = 0; i < n; i++){
        dfs(i);
        C++;
    }

    long long ret = 0;
    
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < i; j++){
//             int ci = country[i];
//             int cj = country[j];
            
//             if(cj == ci) continue;
            
            
//             ret++;
            
//         }
//     }

    int cc = 0;
    for(auto [c, f]: countryCount){
        cc += f;
    }
    
    for(auto [c, f]: countryCount){
        int combinations = (cc - f) * f;
        ret += combinations;
    }
    
        
    return ret / 2;
}