#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

void insertionSort(vector<int> &arr){

    for(int r = 0; r < arr.size(); r++){
        for(int l = r - 1; l != -1; l--){
            if(arr[l + 1] < arr[l]){
                swap(arr[l], arr[l + 1]);
            } else {
                break;
            }
        }
    }
}


int main() {
    vector<int> input = {1,5,7,5,3,2,10};
    bool isInputSorted = true;

    insertionSort(input);

    for(int i = 1; i < input.size(); i++){
        if(input[i] < input[i - 1]) {
            isInputSorted = false;
            break;
        }
    }


    assert(isInputSorted);

    return 0;
}