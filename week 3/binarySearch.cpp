#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while(l <= r){
            int mid = (l + r) / 2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[mid] < target){
                l = mid + 1;
            } else {
                r = mid - 1;
            }  
        }
        
        return -1;
    }

int main() {
    vector<int> in1 = {-1,0,3,5,9,12},
        in2 = {-1,0,3,5,9,12};
    
    assert(search(in1, 9) == 4);
    assert(search(in2, 2) == -1);

    return 0;
}