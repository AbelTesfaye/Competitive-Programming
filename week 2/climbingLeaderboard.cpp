#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    if(ranked.size() == 0) return {1};
    vector<int> ret, arr;
    
    for(int n: ranked){
        if(arr.empty() || arr.back() != n) 
            arr.push_back(n);
    }
    
    reverse(arr.begin(), arr.end());
    
    for(int playerRanking: player){ 
        int index = lower_bound(arr.begin(), arr.end(), playerRanking) - arr.begin();    
        
        if(index == arr.size()) {
            ret.push_back(1);    
            continue;
        }
        
        if(arr[index] == playerRanking){
            int numsToRight = (arr.size() - 1) - index;
            ret.push_back(numsToRight + 1);
            continue;
        }
        
        int numsToRight = (arr.size() - 1) - index;
        ret.push_back(numsToRight + 2);
    }
    
    return ret;
}

int main() {


    return 0;
}