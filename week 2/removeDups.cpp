#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;


int removeDuplicates(vector<int>& nums) {
        int prevNum = INT_MIN;
        int uniqueIndex = 0;
        
        for(int n: nums){
            if(prevNum == n) continue;
            
            nums[uniqueIndex] = n;
            
            uniqueIndex++;
            prevNum = n;
        }
        
        return uniqueIndex;
    }

int main() {
    vector<int> 
        input1 = {1,1,2}, expected1 = {1,2},
        input2 = {0,0,1,1,1,2,2,3,3,4}, expected2 = {0,1,2,3,4};

    int input1Size = removeDuplicates(input1);
    assert(vector<int>(input1.begin(), input1.begin() + input1Size) == expected1);

    int input2Size = removeDuplicates(input2);
    assert(vector<int>(input2.begin(), input2.begin() + input2Size) == expected2);

    return 0;
}