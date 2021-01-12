#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack< pair<int, int> > st;
    
    MinStack() {
        
    }
    
    void push(int x) {
        if(st.empty()){
            st.push({x, x});
            return;
        }
        st.push({x, min(x, st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

int main() {


    return 0;
}