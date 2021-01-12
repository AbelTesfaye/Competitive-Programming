#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

bool isPalindrome(ListNode* head) {
    ListNode * node = head; 
    
    stack<ListNode*> s;
    
    while(node != NULL){
        
        s.push(node);
        
        node = node->next;
    }
    
    node = head;
    
    while(node != NULL && !s.empty()){
        ListNode * temp = s.top();
        s.pop();
        
        if(temp->val != node->val) return false;
        
        node = node->next;
    }
    
    
    return true;
    
    
}

int main() {


    return 0;
}