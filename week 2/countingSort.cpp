#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

int numToIndex(vector<int> arr, int n){
    if(n >= 0) return n;

    // negative indexes refer to elements from last index
    return arr.size() - abs(n);;
}

int main() {
    srand( (unsigned)time(NULL) );

    // handles -100, 0, 100
    vector<int> bucket(201), testArray;

    for(int i = 0; i < 1000; i++){
        int n = (rand() % 200) - 100;
        testArray.push_back(n);
    }

    cout<<"testArray: "; for(int n: testArray) cout<<n<<","; cout<<endl;

    unordered_map<int, int> m;
    for(int n: testArray) {
        bucket[numToIndex(bucket, n)]++;
        m[n]++;
    }

    for(auto &[n, count]: m){
        if(bucket[numToIndex(bucket, n)] != count) {
            cout<<"TEST FAILED!"<<endl;
            return -1;
        }
    }

    cout<<"TEST SUCCEEDED"<<endl;

    return 0;
}