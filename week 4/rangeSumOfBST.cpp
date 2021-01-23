class Solution {
public:
    int ret = 0;
    
    void dfs(TreeNode *node, int low, int high){
        if(node == NULL) return;
        
        dfs(node->left, low, high);
        
        if(node->val >= low && node->val <= high) ret += node->val;
        
        dfs(node->right, low, high);
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        
        return ret;
    }
};