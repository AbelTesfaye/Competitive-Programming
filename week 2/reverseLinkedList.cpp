#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

ListNode * newHead = NULL;
    void reverseListHelper(ListNode* node){
        if(node == NULL) return;
        
        reverseListHelper(node->next);
        
        if(node->next != NULL)
            node->next->next = node;
        else
            newHead = node;
        
        node->next = NULL;
        
}
ListNode* reverseList(ListNode* head) {
    reverseListHelper(head);
    return newHead;
}

int main() {


    return 0;
}