#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

int maximumToys(vector<int> prices, int k) {
    sort(prices.begin(), prices.end());
    int ret = 0, sum = 0;
    
    for(int p: prices){
        if(sum + p < k){
            ret++;
            sum += p;
        } else {
            break;
        }
    }
    
    return ret;
}

int main() {
    vector<int> input = {4,3,2,1};

    assert(3 == maximumToys(input, 7));

    return 0;
}