#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17 && ./a.out

*/
using namespace std;

/*
 FUNCTIONS SHOULD PROBABLY GO UNDER HERE
*/

void sortColors(vector<int>& nums) {
        int zCount = 0, oCount = 0;
        for(int i=0; i< nums.size(); i++){
            int el = nums[i];
            if(el == 0) zCount++;
            else if(el == 1) oCount++;
        }
        
        for(int i=0; i< nums.size(); i++){
            if(zCount > 0) {
                nums[i] = 0;
                zCount--;
            }
            else if(oCount > 0) {
                nums[i] = 1;
                oCount--;
            }
            else nums[i] = 2;
    
        }
    }

int main() {
    vector<int> inout = {2,0,2,1,1,0},
    expected = {0,0,1,1,2,2};

    sortColors(inout);

    assert(inout == expected);

    return 0;
}