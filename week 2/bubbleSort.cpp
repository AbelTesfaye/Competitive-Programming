#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

/*
 FUNCTIONS SHOULD PROBABLY GO UNDER HERE
*/

void bubbleSort(vector<int> &arr){
    bool hasSwapHappened = true;

    while(hasSwapHappened){
        hasSwapHappened = false;
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] < arr[i-1]){
                swap(arr[i], arr[i-1]);
                hasSwapHappened = true;
            }
        }
    }
}

int main() {
    vector<int> input = {1,5,7,5,3,2,10};
    bool isInputSorted = true;

    bubbleSort(input);

    for(int i = 1; i < input.size(); i++){
        if(input[i] < input[i - 1]) {
            isInputSorted = false;
            break;
        }
    }


    assert(isInputSorted);

    return 0;
}