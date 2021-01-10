#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang -std=c++17  && ./a.out

*/
using namespace std;

vector<int> countingSort(vector<int> arr) {
    vector<int> counter(101), ret;
    
    for(int n: arr) counter[n]++;
    
    for(int i = 0; i < 101; i++) 
        while(counter[i]--) 
            ret.push_back(i);

    return ret;
}


int main() {

    assert(countingSort({1,3,2,2}) == vector<int>({1,2,2,3}));

    return 0;
}