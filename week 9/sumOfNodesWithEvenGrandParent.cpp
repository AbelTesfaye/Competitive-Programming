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
    
    void dfs(TreeNode *currentNode, TreeNode *currentNodeParent, TreeNode *currentNodeGrandParent){
        if(!currentNode) return ;
        
        
        dfs(currentNode->left, currentNode, currentNodeParent);
        
        if(currentNodeGrandParent && (currentNodeGrandParent->val & 1) == 0){
            ret+= currentNode->val;
        }
        
        dfs(currentNode->right, currentNode, currentNodeParent);
        
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, NULL, NULL);
        
        return ret;
    }
};