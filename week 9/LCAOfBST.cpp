/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool areBothGreater(TreeNode *p, TreeNode *q, TreeNode *comp){
        int pv = p->val;
        int qv = q->val;
        int cv = comp->val;
        
        if(pv > cv && qv > cv) return true;
        
        return false;
    }
    
    bool areBothLess(TreeNode *p, TreeNode *q, TreeNode *comp){
        int pv = p->val;
        int qv = q->val;
        int cv = comp->val;
        
        if(pv < cv && qv < cv) return true;
        
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *node = root;
        
        while(areBothGreater(p, q, node) || areBothLess(p, q, node)){
            if(areBothGreater(p, q, node)){
                node = node->right;   
            } else {
                node = node->left;
            }
        }
        
        return node;
    }
};