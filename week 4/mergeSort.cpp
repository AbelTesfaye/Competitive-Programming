#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

void mergeSort(vector<int> &arr, int l, int r){
    if(l >= r) return;

    vector<int> storage(r - l + 1);

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    int p1 = l, p2 = mid + 1;
    int i = 0;

    while(true){
        if(p1 <= mid && p2 <= r){
            if(arr[p1] <= arr[p2]){
                storage[i] = arr[p1]; p1++;
            } else {
                storage[i] = arr[p2]; p2++;
            }

        } else if(p1 <= mid){
            storage[i] = arr[p1]; p1++;
        } else if(p2 <= r){
            storage[i] = arr[p2]; p2++;
        } else {
            break;
        }

        i++;
    }

    for(int j = l; j < l + i; j++){
        arr[j] = storage[j - l];
    }

}


int main() {
    srand( (unsigned)time(NULL) );

    vector<int> input = {1,5,7,5,3,2,10};
    bool isInputSorted = true;

    mergeSort(input, 0, input.size() - 1);

    for(int i = 1; i < input.size(); i++){
        if(input[i] < input[i - 1]) {
            isInputSorted = false;
            break;
        }
    }


    assert(isInputSorted);

    return 0;
}