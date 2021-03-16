/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long prev = -2e10;
    bool isValid = true;
    
    void dfs(TreeNode *node){
        if(node == NULL) return;
        
        dfs(node->left);
        
        if(prev >= node->val){
            isValid = false;
            return;
        }
        
        prev = node->val;
        
        dfs(node->right);
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        dfs(root);
        
        return isValid;
    }
};