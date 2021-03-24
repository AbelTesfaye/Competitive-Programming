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
    long long ret = 0;
    int totalSum = 0;
    int M = 1e9 + 7;
    int dfs(TreeNode *node){
        if(node == NULL) return 0;
        
        int l = dfs(node->left);
        int r = dfs(node->right);
        
        node->val = (node->val + l + r) % M;
        
        return node->val;
    }
    
    void dfs2(TreeNode *node){
        if(!node) return;
        
        dfs2(node->left);
        dfs2(node->right);
        
        int withoutSubTree = (totalSum - node->val);
        long long removed = ((long long) withoutSubTree * (long long) (node->val));
        
        ret = max(ret, removed);        
    }
    
    int maxProduct(TreeNode* root) {
        if(!root) return 0;

        dfs(root);
        
        totalSum = root->val;

        dfs2(root);
        
        return ret % M;
    }
};
//763478770