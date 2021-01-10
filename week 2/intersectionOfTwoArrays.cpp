
    #include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17 && ./a.out

*/
using namespace std;

/*
 FUNCTIONS SHOULD PROBABLY GO UNDER HERE
*/

vector<int> intersection(vector<int> nums1, vector<int> nums2) {
        
        unordered_set<int> s(nums1.begin(), nums1.end()), inserted;
        nums1.clear();
        
        for(int n: nums2){
            if(s.find(n) == s.end() || inserted.find(n) != inserted.end()) continue;
            nums1.push_back(n);
            inserted.insert(n);
        }
        
        return nums1;
    }

int main() {

    assert(intersection({1,2,2,1}, {2,2}) == vector<int>{2});
    assert(intersection({4,9,5}, {9,4,9,8,4}) == vector<int>({9,4}));
    
    return 0;
}