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
    int ret = 0;
    int dfs(TreeNode *node){
        if(node == NULL) return 0;
        
        int l = dfs(node->left);
        int r = dfs(node->right);
        
        int pathLen = 1;
        
        if(node->left && node->left->val == node->val) {
            pathLen += l;
            l++;
        } else {
            l = 0;
        }
        
        if(node->right && node->right->val == node->val) {
            pathLen += r;
            r++;
        } else {
            r = 0;
        }
                
        ret = max(ret, pathLen);
        
        return max({l, r, 1});
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        
        dfs(root);   
        
        return ret - 1;
    }
};