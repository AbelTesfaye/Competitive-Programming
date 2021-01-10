#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

/*
 FUNCTIONS SHOULD PROBABLY GO UNDER HERE
*/
 int maxDepth(string s) {
        int ret = 0, currentOpen = 0;;
        
        for(char c: s){
            if(c == '(') currentOpen++;
            if(c == ')') currentOpen--;
            
            ret = max(ret, currentOpen);
            
        }
        
        return ret;
    }

int main() {

    assert(maxDepth("(1)+((2))+(((3)))") == 3);

    return 0;
}