#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17 && ./a.out

*/
using namespace std;

/*
 FUNCTIONS SHOULD PROBABLY GO UNDER HERE
*/
vector<vector<int>> kClosest(vector<vector<int>> points, int K) {
    vector< vector<int> > ret;
    
    priority_queue<pair<int, pair<int, int>>> pq;
    
    for(auto &p: points){
        int x = p[0], y = p[1];
        int dist = (x*x) + (y*y);
        pq.push({dist, {x, y}});
        
        if(pq.size() > K) pq.pop();
    }
    
    while(pq.size()){
        auto p = pq.top(); pq.pop();
        ret.push_back({p.second.first, p.second.second});
    }
    
    return ret;
}
int main() {
    vector<vector<int>> test = {{1,3},{-2,2},{2,-2}};
    vector<vector<int>> expectedResult = {{2,-2},{-2,2}};

    assert(kClosest(test, 2) == expectedResult);

    return 0;
}