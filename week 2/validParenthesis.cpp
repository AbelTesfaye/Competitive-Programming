#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

bool isValid(string s) {
        stack<char> st;
        
        for(char c: s){
            if(c == ')' || c == '}' || c == ']'){
                if(st.empty()) return false;
                
                if(
                    (c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')
                  
                  ){
                    return false;
                }
                st.pop();
            } else {
                st.push(c);
            }
        }
        
        return st.size() == 0;
    }

int main() {

    assert(isValid("{[]}") == true);
    assert(isValid("]") == false);

    return 0;
}