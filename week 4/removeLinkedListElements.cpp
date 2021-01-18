class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head && head->val == val){
            head = head->next;
        }
        
        if(!head) return NULL;
        
        ListNode *prev = head, *c = head->next;
        
        while(c){
            if(c->val == val){
                prev->next = c->next;
            } else {
                prev = c;
            }
            
            c = c->next;
        }
        
        return head;
    }
};