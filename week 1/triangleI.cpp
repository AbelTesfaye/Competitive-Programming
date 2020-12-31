#include<bits/stdc++.h>
using namespace std;

int main(){
    int desiredRowCount = 10;

    for(int y = 1; y <= desiredRowCount; y++){
        for(int x = 0; x < y; x++){
            cout<<"*";
        }
        cout<<endl;
    }
}