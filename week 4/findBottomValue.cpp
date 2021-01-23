
class Solution {
public:
    
    pair<int, int> ret{-1,INT_MAX};
    
    void dfs(TreeNode *node, int level){
        if(node == NULL) return;
        
        dfs(node->left, level + 1);
        
        if(level > ret.first){
            ret = {level, node->val};
        }
        
        dfs(node->right, level + 1);
        
    }
    
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        
        return ret.second;
    }
};