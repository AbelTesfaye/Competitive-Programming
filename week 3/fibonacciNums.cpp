#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

unordered_map <int,int> dp;
    int fib(int N) {
        
        if(N < 0) return N;
        if(N == 0) return 0;
        if(N == 1) return 1;
        
        if(dp.count(N) > 0) return dp[N];
            
        int res = fib(N-1) + fib(N-2);
        
        dp[N] = res;
        return res;
        
    }

int main() {

    assert(fib(3) == 2);

    return 0;
}