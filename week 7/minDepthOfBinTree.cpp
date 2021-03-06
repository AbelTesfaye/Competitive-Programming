class Solution {
public:
    int ret = 2e9;
    
    void dfs(TreeNode *node, int currentLevel){
        if(!node) return;
        if(!node->right && !node->left) ret = min(ret, currentLevel + 1);
        
        dfs(node->left,currentLevel + 1);
        dfs(node->right, currentLevel + 1);
    }
    
    int minDepth(TreeNode* root) {
        
        dfs(root, 0);
        
        if(ret == 2e9) return 0;
        
        return ret;
    }
};