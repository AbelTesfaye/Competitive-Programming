#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        
        int ret = 0;
        for(int i = A.size() - 1; (i - 2) > -1 ; i--){
            int a = A[i-2];
            int b = A[i-1];
            int c = A[i];
            
            if(a + b > c){
                return a + b + c;
            }
        }
        
        return ret;
    }


int main() {
    vector<int> input = {2,1,2};
    
    assert(largestPerimeter(input) == 5);

    return 0;
}