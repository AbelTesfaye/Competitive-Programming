 bool ret = true;
    int prev = -100;

    void dfs(Node *node){
        if(!node) return;
        
        dfs(node->left);
        
        if(prev >= node->data) ret = false;
        prev = node->data;
        
        dfs(node->right);
    }
    bool checkBST(Node* root) {
        dfs(root);
        
        return ret;
    }