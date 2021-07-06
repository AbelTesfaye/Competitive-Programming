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
    
    void dfs(TreeNode *node, int sumSoFar){
        if(node == NULL) return;
        
        sumSoFar *= 10;
        sumSoFar += node->val;
        
        if(node->left == NULL && node->right == NULL){
            
            ret += sumSoFar;
            return;
        }
        
        dfs(node->left, sumSoFar);
        dfs(node->right, sumSoFar);
        
    }
    
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        
        return ret;
    }
};