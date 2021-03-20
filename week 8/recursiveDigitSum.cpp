#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
unordered_map< int, unordered_map<string, int> > m;

// Complete the superDigit function below.
int superDigit(string n, int k) {
    
    long long hash = 0;
    
    for(char c: n){
        hash += c - '0';
    }
    
    hash *= k;
    
    if(hash < 10) return hash;
    
    return superDigit(to_string(hash), 1);

}
