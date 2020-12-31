#include<bits/stdc++.h>
using namespace std;

int main(){
    int desiredRowCount = 5;

    for(int y = 0; y <= desiredRowCount; y++){
        int currentRowStarCount = (y * 2) + 1;
        int padding = ((desiredRowCount * 2 + 1) - currentRowStarCount) / 2;
        for(int i = 0; i < padding; i++) cout << " ";
        for(int x = 0; x < currentRowStarCount; x++){
            cout<<"*";
        }

        cout<<endl;
    }
}