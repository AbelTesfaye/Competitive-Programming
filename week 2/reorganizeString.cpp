#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

// exact same logic as distantBarCodes, but too lazy to change 'barcodes' variable :D
string reorganizeString(string barcodes) {
        
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

        for(int i = 1; i < barcodes.size(); i++){
            if(barcodes[i] == barcodes[i-1]){
                return "";
            }
        }
        
        return barcodes;
}


int main() {

    assert(reorganizeString("aab") == "aba");
    assert(reorganizeString("aaab") == "");

    return 0;
}