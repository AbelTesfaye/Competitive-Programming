#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

ListNode* headItem = NULL;


void swapPairsHelper(ListNode* node, ListNode* leftPairRight){
    if(node == NULL || node->next == NULL) return;
    
    ListNode* rightElem = node->next;
    node->next = node->next->next;
    rightElem->next = node;
    
    if(leftPairRight)
        leftPairRight->next = rightElem;
    
    if(headItem == NULL) headItem = rightElem;
    
    swapPairsHelper(node->next, node);
    
    return;
    
}
ListNode* swapPairs(ListNode* head) {
    if(head && head->next == NULL) headItem = head;
    swapPairsHelper(head,NULL);
    
    return headItem;
}


int main() {


    return 0;
}