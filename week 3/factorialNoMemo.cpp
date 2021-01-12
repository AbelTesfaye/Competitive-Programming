#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

int factorial(int n) {
    if(n == 0) return 1;

    return n * factorial(n-1);
}

int main() {

    assert(factorial(3) == 6);
    
    return 0;
}