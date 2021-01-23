class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL) return NULL;
        
        
        if(t2 == NULL) t2 = new TreeNode(0);
        
        if(t1 == NULL) t1 = new TreeNode(0);
        
        
        
        if(t1->right == NULL && t2->right != NULL) t1->right = new TreeNode(0);
        if(t1->left == NULL && t2->left != NULL) t1->left = new TreeNode(0);
            
        t1->val += t2->val;

        
        mergeTrees(t1->left, t2->left);
        mergeTrees(t1->right, t2->right);

        return t1;
        
    }
};