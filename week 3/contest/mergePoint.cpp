int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode *p = head1;
    
    vector<SinglyLinkedListNode*> h1addr, h2addr;
    
    while(p){
        h1addr.push_back(p);
        p = p->next;
    }
    
    p = head2;
    while(p){
        h2addr.push_back(p);
        p = p->next;
    }
    
    reverse(h1addr.begin(), h1addr.end());
    reverse(h2addr.begin(), h2addr.end());
    
    SinglyLinkedListNode *prevValid = NULL;
    for(int i = 0; i < min(h1addr.size(), h2addr.size()); i++){
        if(h1addr[i] != h2addr[i]) break;
        
        prevValid = h1addr[i];
    }
    
    
    return prevValid->data;
    
}