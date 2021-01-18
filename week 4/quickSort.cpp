#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

void quickSort(vector<int> &arr, int l, int r){
    if(l >= r) return;

    int randomIndex = (rand() % (r - l + 1)) + l;

    swap(arr[randomIndex], arr[r]);

    int lessOrEqual = l;
    for(int i = l; i <= r; i++){
        if(arr[i] <= arr[r]){
            swap(arr[i], arr[lessOrEqual]);
            lessOrEqual++;
        }
    }

    quickSort(arr, l, lessOrEqual - 2);
    quickSort(arr, lessOrEqual, r);
}


int main() {
    srand( (unsigned)time(NULL) );

    vector<int> input = {1,5,7,5,3,2,10};
    bool isInputSorted = true;

    quickSort(input, 0, input.size() - 1);

    for(int i = 1; i < input.size(); i++){
        if(input[i] < input[i - 1]) {
            isInputSorted = false;
            break;
        }
    }

    assert(isInputSorted);

    return 0;
}