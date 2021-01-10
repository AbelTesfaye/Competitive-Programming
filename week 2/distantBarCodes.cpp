#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang -std=c++17  && ./a.out

*/
using namespace std;

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> m;
    pair<int, int> biggest = {-1, -1};
    
    for(int b: barcodes){
        m[b]++;
        
        if(biggest.first == -1 || m[b] > biggest.second){
            biggest = {b, m[b]};
        }
    }
    
    int i = 0;
    for(; i < barcodes.size() && biggest.second; i += 2){ 
        int biggestNum = biggest.first;
        
        barcodes[i] = biggestNum;
        m[biggestNum]--;
        biggest.second--;
    }
    
    for(auto &[b, count]: m){
        if(count == 0) continue;
        
        bool isCountEnded = false;
        // consume all remaining even indexes
        while(count && ((i & 1) == 0) && i < barcodes.size()){
            
            barcodes[i] = b;
            
            i += 2;
            count--;
            
            if(count == 0) {
                isCountEnded = true;
                break;
            }
        }
        
        if(isCountEnded) continue;

        if((i & 1) == 0) i = 1;

        // start from odd indexes if evens are all consumed   
        while(count && (i & 1) && i < barcodes.size()){
            barcodes[i] = b;
            
            i += 2;
            count--;
        }

    }
    
    return barcodes;
}

int main() {

    vector<int> inout = {1,1,2,2,3,3,4,4,5,5};
    
    rearrangeBarcodes(inout);

    bool noTwoAdj = true;
    for(int i = 1; i < inout.size(); i++){
        if(inout[i] == inout[i-1]){
            noTwoAdj = false;
            break;
        }
    }


    assert(noTwoAdj);

    return 0;
}