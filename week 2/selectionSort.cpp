#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

void selectionSort(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        int minIndex = i;
        for(int j = i; j < arr.size(); j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> input = {1,5,7,5,3,2,10};
    bool isInputSorted = true;

    selectionSort(input);

    for(int i = 1; i < input.size(); i++){
        if(input[i] < input[i - 1]) {
            isInputSorted = false;
            break;
        }
    }


    assert(isInputSorted);

    return 0;
}