#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
        if(tasks.size() == 0) return 0;
        int counts[26] = {0};
        
        for(char c: tasks){
            counts[c - 'A']++;
        }
        
        sort(counts, counts + 26, [](auto &a, auto &b){
            return a > b;
        });
        
        int availableGaps = (counts[0] - 1) * n;
        
        for(int i = 1; i<tasks.size(); i++){
            if(counts[i] == 0)
                break;
            if(counts[i] == counts[0]){
                availableGaps -= (counts[i] - 1);
            }else{
                availableGaps -= counts[i];   
            }
            
            if(availableGaps <= 0)
                return tasks.size();
        }
        
        return tasks.size() + availableGaps;
    }

int main() {
    vector<char> input = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    int n = 2;

    assert(leastInterval(input, n) == 16);

    return 0;
}