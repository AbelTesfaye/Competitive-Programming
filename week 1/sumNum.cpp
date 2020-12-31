#ifndef sumnum
#define sumnum

#include <bits/stdc++.h>

using namespace std;


vector<int> addBig(vector<int> &n1, vector<int> &n2){
    // Note: both numbers need to be positive
    // space: O(1); time: O(n) 

    vector<int> &biggerArray = n1.size() > n2.size() ? n1 : n2;

    biggerArray.push_back(0);

    for(int i = biggerArray.size() - 2; i != -1; i--){
        biggerArray[i + 1] = biggerArray[i];
    }

    biggerArray[0] = 0;

    int currentIndex= 0, currentCarry = 0;
    while(currentIndex < biggerArray.size()){
        int topNum = 0, bottomNum = 0;

        topNum = n1[n1.size() - currentIndex - 1];
        if(n2.size() > currentIndex){
            bottomNum = n2[n2.size() - currentIndex - 1];
        } 

        int sum = topNum + bottomNum; 
        int currentIndexValue = sum % 10;
        sum /= 10;
        currentCarry = sum % 10;

        int trueIndex = biggerArray.size() - currentIndex - 1;
        biggerArray[trueIndex]=currentIndexValue;
        biggerArray[trueIndex - 1] += currentCarry;

        currentIndex++;
    }

    // trim leading 0's
    int start = 0;
    for(int i = 0; i < biggerArray.size(); i++){
        if(biggerArray[i] != 0 || start != 0){
            biggerArray[start] = biggerArray[i];
            start++;
        }
    }
    int p = biggerArray.size() - start;
    while(p--){
        biggerArray.pop_back();
    }
    if(biggerArray.size() == 0) biggerArray.push_back(0);

    return biggerArray;
}

vector<int> subtractBig(vector<int> &n1, vector<int> &n2){
    // assumes both numbers are positive
    // n1 needs to be larger than n2
    // space: O(n); time: O(n); space could potentially be minimized to O(1)

    int n1s = n1.size(), n2s = n2.size();

    int padding = max(n1.size(), n2.size()) - min(n1.size(), n2.size());

        int p = padding;

        while(padding--){
            n2.push_back(0);
        }

        for(int i = n2.size() - 1 - p; i != -1; i--){
            n2[i + p] = n2[i];
            
            if(i < p){
                n2[i] = 0;
            }
           
        }
    
        vector<int> ret(n1s + 1);

        for(int i = 0; i < n1s; i++){
            int ri = n1s - 1 - i;
            
            if(n1[ri] < n2[ri]){
                int borrowIndex = ri - 1;
                while(n1[borrowIndex] == 0){
                    n1[borrowIndex] = 9;
                    borrowIndex--;
                }
                n1[borrowIndex]--;
                n1[ri] += 10;
            }

            int s = n1[ri] - n2[ri];
            ret[ri + 1] += s % 10;
            s /= 10;
            ret[ri - 1 + 1] += s;    
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

bool isFirstBigger(vector<int> &n1, vector<int> &n2){
    if(n1.size() == n2.size()){
        for(int i = 0; i < n1.size(); i++){
            if(abs(n1[i]) == abs(n2[i])) continue;

            return abs(n1[i]) > abs(n2[i]);
        }
    }

    return n1.size() > n2.size();
}

vector<int> sumNum(vector<int> n1, vector<int> n2){
    // space: O(n); time: O(n) -> n is the size of the biggest array 

    if(!isFirstBigger(n1, n2)){
        auto temp = n1;

        n1 = n2;
        n2 = temp;
    }

    if(n1.size() == 1 && n1[0] == 0) return n2;
    if(n2.size() == 1 && n2[0] == 0) return n1;

    if(n1[0] < 0 && n2[0] < 0){
        n1[0]*=-1, n2[0]*=-1;

        auto ret = addBig(n1, n2);
        ret[0] *= -1;
        return ret;
    } 

    if(n1[0] > 0 && n2[0] > 0){
        return addBig(n1, n2);
    } 

    if(n1[0] < 0 && n2[0] > 0){
        n1[0]*=-1;
        auto ret = subtractBig(n1, n2);
        ret[0] *= -1;
        return ret;
    }

    if(n1[0] > 0 && n2[0] < 0){
        n2[0]*=-1;
        return subtractBig(n1, n2);
    }

    return {};
}
#endif
