#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector< vector<int> > ret;
        
        for(int r = 0; r < R; r++){
            for(int c = 0; c < C; c++){
                ret.push_back({r, c});   
            }
        }
        
        sort(ret.begin(), ret.end(), [=](auto &a, auto &b){
            int distA = abs(a[0] - r0) + abs(a[1] - c0);
            int distB = abs(b[0] - r0) + abs(b[1] - c0);
            
            return distA < distB;
        });
        
        return ret;
    }

int main() {
    vector< vector<int> > expected = { {0,0}, {0,1} };
    auto out = allCellsDistOrder(1,2,0,0);
    
    assert(out == expected);

    return 0;
}