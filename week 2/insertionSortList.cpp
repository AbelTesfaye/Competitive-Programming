#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        
        while(head){
            ListNode *next = head->next;
            
            head->next = dummy->next;
            dummy->next = head;
            
            ListNode *prev = dummy;
            while(head->next && head->next->val < head->val){
                ListNode *temp = head->next;
                
                head->next = head->next->next;
                temp->next = head;
                prev->next = temp;
                
                prev = temp;
            }
            
            head = next;
        }
        
        return dummy->next;
    }


int main() {


    return 0;
}