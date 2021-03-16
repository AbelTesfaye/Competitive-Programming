#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

void radixSort(vector<int> &arr){
    

    for(int rad = 0; rad < (sizeof(int) * 8) - 1 ; rad++){
        int mask = 1 << rad;
        vector<int> ar, zeroes, ones;;

        for(int n: arr){
            if((mask & n)) {
                ones.push_back(n); 
            } else {
                zeroes.push_back(n); 
            }
        }

        for(int z: zeroes) ar.push_back(z);
        for(int o: ones) ar.push_back(o);
        
        arr = ar;
    }

}

int main() {
    vector<int> input = {1,5,7,5,3,2,10};
    bool isInputSorted = true;

    radixSort(input);

    for(int i = 1; i < input.size(); i++){
        if(input[i] < input[i - 1]) {
            isInputSorted = false;
            break;
        }
    }


    assert(isInputSorted);

    return 0;
}