#ifndef multnum
#define multnum

#include <bits/stdc++.h>
#include "sumNum.cpp"

using namespace std;

vector<int> multBig(vector<int> n1, vector<int> n2){
    // space: O(n1.size() + n2.size()); time(n1.size() x n2.size());

    if(n1.size() < n2.size()){
        auto temp = n1;

        n1 = n2;
        n2 = temp;
    }
    
    vector<int> ret(n1.size() + n2.size());
    for(int j = n2.size() - 1; j != -1; j--){
        for(int i = n1.size() - 1; i != -1; i--){
            int n1v = n1[i], n2v = n2[j];

            int retShift = n2.size() - 1 - j , ri = (ret.size() -1) - retShift - (n1.size() - 1 - i);
            int val = (n1v * n2v) + ret[ri];
            ret[ri] = val % 10;
            val /= 10;
            ret[ri - 1] += val;
        }
    }

    // trim leading 0's
    int start = 0;
    for(int i = 0; i < ret.size(); i++){
        if(ret[i] != 0 || start != 0){
            ret[start] = ret[i];
            start++;
        }
    }
    int pop = ret.size() - start;
    while(pop--){
        ret.pop_back();
    }
    if(ret.size() == 0) ret.push_back(0);

    return ret;
}

vector<int> multNum(vector<int> &n1, vector<int> &n2){
    // space: O(n1.size() + n2.size()); time: O(n1.size() x n2.size())

    if((n1.size() == 1 && n1[0] == 0) || (n2.size() == 1 && n2[0] == 0)) return {0};
    
    bool isNeg = false;

    if((n1[0] < 0 && n2[0] > 0) || (n1[0] > 0 && n2[0] < 0)){
        isNeg = true;
    }

    n1[0] = abs(n1[0]);
    n2[0] = abs(n2[0]);

    vector<int> ret = multBig(n1, n2);

    if(isNeg)
        ret[0] = -ret[0];

    return ret;
}
#endif