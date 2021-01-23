class Solution {
public:
    bool existsAndIsINTMAX(TreeNode *node){
        if(!node) return true;
        
        return node->val == INT_MAX;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<int> ret;
        
        stack<TreeNode*> st;
        
        st.push(root);
        
        while(!st.empty()){
            TreeNode *topNode = st.top();
            
            while(st.top()->left && st.top()->left->val != INT_MAX){
                st.push(st.top()->left);
            }

            if(st.top()->right && st.top()->right->val != INT_MAX){
                st.push(st.top()->right);
                continue;
            }
            
            
            if(existsAndIsINTMAX(st.top()->right) && 
                 existsAndIsINTMAX(st.top()->left)
              ){
                
                ret.push_back(st.top()->val);
                st.top()->val = INT_MAX;
                st.pop();
            }
        }
        
        
        
        return ret;
    }
};