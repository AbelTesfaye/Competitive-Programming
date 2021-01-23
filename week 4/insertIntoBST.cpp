
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *currentNode = root;
    
        auto newNode = new TreeNode(val);

        if(!root) return newNode;

        while(true){

            if(val > currentNode->val){
             if(!currentNode->right){
                currentNode->right = newNode;
                return root;
            }

                currentNode = currentNode->right;
            }
            else{
                
            if(!currentNode->left){
                currentNode->left = newNode;
                return root;
            }

                currentNode = currentNode->left;
            }

        }
        
    }
};