bool has_cycle(SinglyLinkedListNode* head) {
    
    SinglyLinkedListNode *l = head, *r = head;
    
    while(l){
        if(!r || r->next == NULL) return false;
        
        l=l->next;
        r=r->next;
        r=r->next;
        
        if(l!= NULL && l  == r) return true;
    }
    
    return false;

}