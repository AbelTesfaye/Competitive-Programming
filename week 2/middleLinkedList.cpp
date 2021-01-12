#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

ListNode* middleNode(ListNode* head) {
        ListNode *l = head;
        ListNode *r = head;
        
        while(1){
            if(r==NULL || r->next == NULL){
                break;
            }
            r=r->next;
            r=r->next;
            l=l->next;
        }
        
        return l;
    }


int main() {


    return 0;
}