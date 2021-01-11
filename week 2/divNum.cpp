#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
#include "../week 1/multNum.cpp"
#include "../week 1/sumNum.cpp"

using namespace std;

bool isFirstBiggerOrEqualTo(vector<int> &n1, vector<int> &n2){
    if(n1.size() == n2.size()){
        for(int i = 0; i < n1.size(); i++){
            if(abs(n1[i]) == abs(n2[i])) {
                if(i == n1.size() - 1) return true;

                continue;
            }

            return abs(n1[i]) > abs(n2[i]);
        }
    }

    return n1.size() > n2.size();
}

pair< vector<int>, vector<int> > divBig(vector<int> n1, vector<int> n2){
    vector<int> ret1, negN2 = n2;
    negN2[0] *= -1;

    int l = 0;
    for(int r = 0; r < n1.size(); r++){
        // grow range till "divisible" 
        // i.e nums in range [l,r] should be bigger than or equal to n2

        vector<int> currentRange(n1.begin() + l, n1.begin() + r + 1);

        if(isFirstBiggerOrEqualTo(currentRange, n2)){
            // perform division
            int timesSubtracted = 0;

            while(true){
                
                currentRange = sumNum(currentRange, negN2);
                timesSubtracted++;

                for(int i = r; i >= l; i--){
                    n1[i] = 0;
                }

                if(currentRange == vector<int>{0}){
                    l = r + 1;
                    break;
                } else if(isFirstBigger(n2, currentRange)){
                    
                    int remI = r;
                    for(int i = currentRange.size() - 1; i != -1; i--){
                        int c = currentRange[i];

                        l = remI;
                        n1[remI] = c;
                        remI--;
                    }

                    break;
                } 
            }

            ret1.push_back(timesSubtracted);
        } else {
            ret1.push_back(0);
        }
    }

    // trim leading 0's for quotient
    int start = 0;
    for(int i = 0; i < ret1.size(); i++){
        if(ret1[i] != 0 || start != 0){
            ret1[start] = ret1[i];
            start++;
        }
    }
    int pop = ret1.size() - start;
    while(pop--){
        ret1.pop_back();
    }
    if(ret1.size() == 0) ret1.push_back(0);

    // trim leading 0's for reminder
    start = 0;
    for(int i = 0; i < n1.size(); i++){
        if(n1[i] != 0 || start != 0){
            n1[start] = n1[i];
            start++;
        }
    }
     pop = n1.size() - start;
    while(pop--){
        n1.pop_back();
    }
    if(n1.size() == 0) n1.push_back(0);


    return {ret1, n1};
}

// performs n1 / n2
pair< vector<int>, vector<int> > divNum(vector<int> &n1, vector<int> &n2){
    if(n2 == vector<int>{0}) return {};
    
    bool isNeg = false;

    if((n1[0] < 0 && n2[0] > 0) || (n1[0] > 0 && n2[0] < 0)){
        isNeg = true;
    }

    n1[0] = abs(n1[0]);
    n2[0] = abs(n2[0]);

    auto ret = divBig(n1, n2);

    if(isNeg) {
        ret.first[0] = -ret.first[0];
    }

    return ret;
}

int main() {
    vector<int> n1,n2;

    // 10^1000 / 10^999 = 10
    n1 = vector<int>(1001); n1[0] = 1;
    n2 = vector<int>(1000); n2[0] = 1;
    vector<int> expectedQuotient = {1,0};
    vector<int> expectedReminder = {0};
    
    auto out = divNum(n1,n2);
    assert(out.first == expectedQuotient);
    assert(out.second == expectedReminder);

    cout<<"quotient: "; for(int n: out.first) cout<<n<<","; cout<<endl;
    cout<<"reminder: "; for(int n: out.second) cout<<n<<","; cout<<endl;

    return 0;
}