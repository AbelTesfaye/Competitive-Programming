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
    int numComponents(ListNode* head, vector<int>& G) {
        if(G.size() == 0) return 0;
        
        unordered_map<ListNode* , ListNode*>  prev;
        
        unordered_set<int> s;
        for(int i: G) s.insert(i);
                
        ListNode *node = head, *p = NULL;
        while(node){
            prev[node] = p;
           
            p = node;
            node = node->next;
        }
        
        prev[NULL] = p;
        
        int ret = 0;
        int groupSize = 0;
        
        ListNode *c = prev[NULL], *lastGroupLastElem = NULL;
        
        while(c){
            
            if(s.find(c->val) != s.end() && lastGroupLastElem == c->next){// is in group
                
                groupSize++;
                if(groupSize == 1){
                    ret++;
                }
                
            } else {
                groupSize = 0;
            }
            
            lastGroupLastElem = c;
            c = prev[c];
        }
        
        
        return ret;
    }
};