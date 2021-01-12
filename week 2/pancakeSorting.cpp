#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ret;
        int numToSeek = arr.size();
        
        while(numToSeek){
            int foundI = find(arr.begin(), arr.begin() + numToSeek, numToSeek) - arr.begin();
            
            if(numToSeek - 1 == foundI) {
                numToSeek--;
                continue;
            }
            
            int p =  foundI + 1;
            reverse(arr.begin(), arr.begin() + p);
            ret.push_back(p);
            
            reverse(arr.begin(), arr.begin() + numToSeek);
            
            ret.push_back(numToSeek);
            
            numToSeek--;
        }
        
        return ret;
    }

int main() {

    //  copy paste function on leetcode 

    return 0;
}