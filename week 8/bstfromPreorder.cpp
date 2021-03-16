TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> s;
        
        TreeNode *dummy = new TreeNode(INT_MAX);
        s.push(dummy);
        
        for(int i: preorder){
            
            TreeNode * newNode = new TreeNode(i);
            while(true){
                if(newNode->val < s.top()->val){
                    s.top()->left = newNode;
                    s.push(newNode);
                    break;
                }else{
                    TreeNode *prev = s.top(); s.pop();

                    if(newNode->val > prev->val && newNode->val < s.top()->val){
                        prev->right = newNode;
                        s.push(newNode);
                        break;
                    }   
                }       
            } 
        }
        
        return dummy->left;
    }