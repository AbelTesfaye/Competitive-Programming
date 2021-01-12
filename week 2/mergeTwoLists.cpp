#include <bits/stdc++.h>
/*

FOR FAST COPY-PASTE COMPILE AND RUN:

clang++-6.0 -std=c++17  && ./a.out

*/
using namespace std;

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* newHead = NULL;
        ListNode *tailNode = NULL;

        while(!(l1 == NULL && l2 == NULL))
        {
            ListNode * pickedNode = NULL;

            if(l1 != NULL && l2 != NULL)
            {
                if(l1->val > l2->val)
                {
                    pickedNode = l2;
                    l2 = l2->next;
                }
                else
                {
                    pickedNode = l1;
                    l1 = l1->next;
                }
            }

            else if(l1 == NULL && l2 != NULL)
            {
                pickedNode = l2;
                l2 = l2->next;
            }
            else if(l2 == NULL && l1 != NULL)
            {
                pickedNode = l1;
                l1 = l1->next;
            }

            if(newHead == NULL)
            {
                newHead = pickedNode;
                tailNode = pickedNode;
            }
            else
            {
                tailNode->next = pickedNode;
            }

            tailNode = pickedNode;
        }

        return newHead;
    }

int main() {


    return 0;
}