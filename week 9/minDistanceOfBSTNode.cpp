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
    int ret = INT_MAX;
    int prev = -2e9;
    void dfs(TreeNode *node){
        if(!node) return;
        
        dfs(node->left);
        
        ret = min(ret, node->val - prev);
        prev = node->val;
        
        dfs(node->right);
        
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
                
        return ret;
    }
};