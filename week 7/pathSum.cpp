class Solution {
public:
    bool hasPathSumHelper(TreeNode* node, int sum,  int sumSoFar){
        if(node == NULL) return false;
        
        int sumTillHere = sumSoFar + node->val;
        
        bool isLeftSumExist = hasPathSumHelper(node->left, sum, sumTillHere);
        bool isRightSumExist = hasPathSumHelper(node->right, sum, sumTillHere);
        
        return  node->left == NULL && node->right == NULL && sumTillHere == sum || isLeftSumExist || isRightSumExist;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        
        return hasPathSumHelper(root, sum,0);
        
    }
};