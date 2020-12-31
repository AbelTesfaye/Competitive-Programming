#include <bits/stdc++.h>
#include "sumNum.cpp"
#include "multNum.cpp"

void printVec(vector<int> &v){
    for(auto i: v){
        cout<<i<<",";
    }
    cout<<endl;
}

int main()
{
    vector<int> n1, n2, v;

    printVec(v = sumNum(n1 = {9},n2 = {-5})), assert((v == vector<int>{4}));
    printVec(v = sumNum(n1 = {-5},n2 = {9})), assert((v == vector<int>{4}));
    printVec(v = sumNum(n1 = {-9},n2 = {5})), assert((v == vector<int>{-4}));
    printVec(v = sumNum(n1 = {1,2,3},n2 = {-1})), assert((v == vector<int>{1,2,2}));
    printVec(v = sumNum(n1 = {-1},n2 = {1,2,3})), assert((v == vector<int>{1,2,2}));
    printVec(v = sumNum(n1 = {1,2,3},n2 = {-1, 2, 3})), assert((v == vector<int>{0}));
    printVec(v = sumNum(n1 = {-1,2,3},n2 = {-1, 2, 3})), assert((v == vector<int>{-2, 4, 6}));
    printVec(v = sumNum(n1 = {1,2,3},n2 = {0})), assert((v == vector<int>{1,2,3}));
    printVec(v = sumNum(n1 = {-1,2,3},n2 = {0})), assert((v == vector<int>{-1,2,3}));
    printVec(v = sumNum(n1 = {1,2,3},n2 = {-1,0})), assert((v == vector<int>{1,1,3}));
    printVec(v = sumNum(n1 = {9,9},n2 = {9,9})), assert((v == vector<int>{1,9, 8}));
    printVec(v = sumNum(n1 = {-9,9},n2 = {-9,9})), assert((v == vector<int>{-1,9, 8}));
    printVec(v = sumNum(n1 = {2,4,6},n2 = {9,8,4,0})), assert((v == vector<int>{1,0,0,8,6}));

    printVec(v = multNum(n1 = {-1,2,3},n2 = {0})), assert((v == vector<int>{0}));
    printVec(v = multNum(n1 = {0},n2 = {0})), assert((v == vector<int>{0}));
    printVec(v = multNum(n1 = {-1,2,3},n2 = {2})), assert((v == vector<int>{-2, 4, 6}));
    printVec(v = multNum(n1 = {-1,2,3},n2 = {4})), assert((v == vector<int>{-4, 9, 2}));
    printVec(v = multNum(n1 = {-1,2,3},n2 = {1,0})), assert((v == vector<int>{-1, 2, 3, 0}));
    printVec(v = multNum(n1 = {-1,2,3},n2 = {8,2})), assert((v == vector<int>{-1,0,0, 8, 6}));
    printVec(v = multNum(n1 = {-1,2,3},n2 = {-8,2})), assert((v == vector<int>{1,0,0, 8, 6}));
    printVec(v = multNum(n1 = {1,2,3},n2 = {-8,2})), assert((v == vector<int>{-1,0,0, 8, 6}));
    
    // 10^10000 * -10^10000 = -10^20000
    n1 = vector<int>(10001); n1[0] = 1;
    n2 = vector<int>(10001); n2[0] = -1;
    vector<int> expected = vector<int>(20001); expected[0] = -1;
    printVec(v = multNum(n1,n2)), assert((v == expected));

    // 10^10000 * 10^10000 = 10^20001
    n1 = vector<int>(10001); n1[0] = 1;
    n2 = vector<int>(10001); n2[0] = 1;
    expected = vector<int>(20001); expected[0] = 1;
    printVec(v = multNum(n1,n2)), assert((v == expected));

    cout<<"ALL TEST CASES PASSED!"<<endl;

    return 0;
}
