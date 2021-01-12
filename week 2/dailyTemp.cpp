#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

/*
 FUNCTIONS SHOULD PROBABLY GO UNDER HERE
*/

vector<int> dailyTemperatures(vector<int>& T) {
        unordered_map<int, int> m;
        
        for(int i = T.size() - 1; i != -1; i--){
            int currentTemp = T[i];
            m[currentTemp] = i;
            
            T[i] = INT_MAX;
            for(int t = currentTemp + 1; t <= 100; t++){
                if(m[t] == 0) continue;
                
                T[i] = min(T[i], m[t] - i);
            }
            
            if(T[i] == INT_MAX) T[i] = 0;
        }
        
        return T;
    }

int main() {

    vector<int> input = {73,74,75,71,69,72,76,73};

    assert((dailyTemperatures(input) == vector<int> {1,1,4,2,1,1,0,0} ));

    return 0;
}