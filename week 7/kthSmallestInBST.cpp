class Solution {
public:
    int ret;
    
    void dfs(TreeNode *node, int &k){
        if(node == NULL)
            return;
        dfs(node->left, k); 
        
        k--;
        if(k == 0){
            ret = node->val;
            return;
        }
        
        dfs(node->right, k);
    }
    
    int kthSmallest(TreeNode* root, int &k) {
        dfs(root, k);
        
        return ret;
    }
};