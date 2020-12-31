class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL){
            return l2;
        } else if(l2 == NULL){ 
            return l1;
        }
        
        ListNode* dummy = new ListNode();
        ListNode* headDummy = dummy;

        int carry = 0;
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            
            int toPlace;
            if(sum < 10){
                toPlace = sum;
                carry = 0;
            } else {
                toPlace = sum % 10;
                carry = sum / 10;
            }
            
            dummy->next = new ListNode(toPlace);
            dummy = dummy->next;
            
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l1 || l2){
            ListNode *remainingNode = NULL;
            if(l1) 
                remainingNode = l1;
            else 
                remainingNode = l2;
            
            while(remainingNode){
                int sum = carry + remainingNode->val;
                
                int toPlace;
                if(sum < 10){
                    toPlace = sum;
                    carry = 0;
                } else {
                    toPlace = sum % 10;
                    carry = sum / 10;
                }
                
                dummy->next = new ListNode(toPlace);
                dummy = dummy->next;
                
                remainingNode = remainingNode->next;
            }
            
        } 
        
        
        if(carry != 0){
                dummy->next = new ListNode(carry);
            }
        
        return headDummy->next;
    }
};