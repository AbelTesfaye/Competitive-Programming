#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

int getCurrentGridSfcArea(vector< vector<int> > &arr, int x, int y){
    int currentHeight = arr[y][x];
    
    int ret = (arr[y][x] * 4) + 2;
    
    int lHeight = 0, rHeight = 0, tHeight = 0, bHeight = 0;
    
    if(x - 1 != -1) lHeight = min(currentHeight, arr[y][x - 1]);
    if(x + 1 != arr[0].size()) rHeight = min(currentHeight, arr[y][x + 1]);
    
    if(y - 1 != -1) bHeight = min(currentHeight, arr[y - 1][x]);
    if(y + 1 != arr.size()) tHeight = min(currentHeight, arr[y + 1][x]);
    int totalReduction = lHeight + rHeight + tHeight + bHeight;
    
    return ret - totalReduction;
}

// Complete the surfaceArea function below.
int surfaceArea(vector<vector<int>> A) {
    int ret = 0;
    for(int y = 0; y < A.size(); y++){
        for(int x = 0; x < A[0].size(); x++){
            ret += getCurrentGridSfcArea(A, x, y);
        }
    }

    return ret;
}

int main() {
    // too lazy to make tests, just copy-paste on HR :)

    return 0;
}