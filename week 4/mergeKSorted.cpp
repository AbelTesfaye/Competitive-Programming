class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        removeEmptys(lists);
        if(lists.size() == 0) return 0;

        while(lists.size() != 1) {
            for(int i = 0; i < lists.size(); i += 2){
                if(i + 1 == lists.size()) 
                    continue;
                lists[i] = mergeToFirst(lists[i], lists[i + 1]);
                lists[i+1] = NULL;
                
            }
            removeEmptys(lists);
        }

        return lists[0];
    }
    
    void removeEmptys(vector<ListNode *> &lists){
        int i = 0;
        while(i < lists.size()){
            if(lists[i] == NULL){
                lists.erase(lists.begin() + i);
            } else {
                i++;
            }
        }
    }

    ListNode *mergeToFirst(ListNode *h1, ListNode *h2){
        ListNode *head = NULL;
        ListNode *prev = NULL;

        while(h1 != NULL || h2 != NULL){
            ListNode *picked = NULL;

            if(h1 != NULL && h2 != NULL) {
                if(h1->val < h2->val){
                    picked = h1; 
                    h1 = h1->next;
                }else{
                    picked = h2;
                    h2 = h2->next;
                }
            } else {
                if(h1 != NULL){
                    picked = h1;
                    h1 = h1->next;
                } else {
                    picked = h2;
                    h2 = h2->next;
                }
            }

            if(head == NULL){
                head = picked;
                prev = head;
            } else {
                prev->next = picked;
                prev = prev->next;
            }
        }

        return head;
    }
};