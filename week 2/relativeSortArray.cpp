#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ret;
        
        map<int, int> m;
        
        for(int n: arr1) m[n]++;
        
        for(int n: arr2){
            while(m[n]--){
                ret.push_back(n);    
            }
        }
        
        for(auto &[n, count]: m) {
            for(int i = 0; i < count; i++){
                ret.push_back(n);    
            }
        }
        
        return ret;
    }

int main() {
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19}, arr2 = {2,1,4,3,9,6},
        expected = {2,2,2,1,4,3,3,9,6,7,19};

    assert(relativeSortArray(arr1, arr2) == expected);

    return 0;
}