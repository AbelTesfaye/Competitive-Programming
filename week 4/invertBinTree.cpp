class Solution {
public:
    void dfs(TreeNode *leftNode, TreeNode *rightNode, TreeNode *leftNodeParent, TreeNode *rightNodeParent){
        if(leftNode == NULL && rightNode == NULL) return;
        if(leftNode && rightNode){
            swap(leftNode->val, rightNode->val);
        }else{
            if(!leftNode){
                TreeNode * newNode = new TreeNode(rightNode->val);
                leftNode = newNode;
                
                if(rightNodeParent->right == rightNode){
                    leftNodeParent->left = newNode;
                    rightNodeParent->right = NULL;

                }else{
                    leftNodeParent->right = newNode;
                    rightNodeParent->left = NULL;

                }
                
            }else{
                TreeNode * newNode = new TreeNode(leftNode->val);
                rightNode = newNode;
                
                if(leftNodeParent->right == leftNode){
                    rightNodeParent->left = newNode;
                    leftNodeParent->right = NULL;
                }else{
                    rightNodeParent->right = newNode;
                    leftNodeParent->left = NULL;
                }
                
                
            }
        }
        
        dfs(leftNode->right, rightNode->left, leftNode, rightNode);
        dfs(leftNode->left, rightNode->right, leftNode, rightNode);
        
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        
        dfs(root->left, root->right, root, root);
        
        return root;
    }
};