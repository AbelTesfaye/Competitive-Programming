/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        
        ListNode *dummy = new ListNode();
        dummy->next = head;
        
        // [0, 1,2,3,4]
        // [0, 1]
        // [0]
        
        ListNode *l = dummy;
        while(l && l->next && l->next->next){
            ListNode *m = l->next,*r = l->next->next;
            
            l->next = r;
            m->next = r->next;
            r->next = m;
                        
            l = m;
        }
        
        return dummy->next;
    }
};