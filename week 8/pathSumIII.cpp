class Solution {
public:
    int count = 0;
    
    int pathSum(TreeNode* root, int sum) {
        traverse(root, sum);
        return count;
    }
    
    void traverse(TreeNode* root, int sum) {
        if(!root) return;
        hasPathSum(root, sum);
        traverse(root->left, sum);
        traverse(root->right, sum);    
    }
    void hasPathSum(TreeNode* root, int sum) {
        if(!root && sum != 0) return;
        if(!root && sum == 0) return;
        sum -= root->val;
        if(sum == 0)
            count++;
        hasPathSum(root->left, sum);
        hasPathSum(root->right, sum);
        return;
    }
};