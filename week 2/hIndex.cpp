#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end(), greater<int>());
        
        int ret = 0;
        for(int i = 0; i < citations.size(); i++){            
            if(citations[i] >= i + 1){
                ret = i + 1;
            } else {
                break;
            }
        }
        
        return ret;
    }


int main() {
    vector<int> input = {1,2,3,4,5,6,7,8,9,10};
    
    assert(hIndex(input) == 5);

    return 0;
}