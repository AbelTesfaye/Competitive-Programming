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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ll;
        
        ListNode *n = head;
        while(n) {
            ll.push_back(n->val);
            
            n = n->next;
        }
        
        vector<int> ret(ll.size());
        
        stack<int> s;
        for(int i = ll.size() - 1; i != -1; i--){
            while(!s.empty() && ll[i] >= s.top()) {s.pop();}
            
            if(!s.empty()){
                ret[i] = s.top();
            }
            
            s.push(ll[i]);
        }
        
        return ret;
    }
};