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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ret;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(q.size()){
            int n = q.size();
            bool inserted = false;
            
            while(n){
                TreeNode *p = q.front(); q.pop();
                
                if(!inserted){
                    ret.push_back(p->val);
                }
                
                if(p->right) q.push(p->right);
                if(p->left) q.push(p->left);
                
                inserted = true;
                n--;
            }
            
        }
        
        return ret;
    }
};