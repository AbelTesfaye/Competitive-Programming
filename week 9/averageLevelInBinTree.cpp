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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        while(q.size()){
            int n = q.size();
            double levelSum = 0, levelCount = n;
            
            while(n){
                auto p = q.front();q.pop();
                levelSum += p->val;
                
                if(p->left) q.push(p->left);
                
                if(p->right) q.push(p->right);
                
                n--;
            }
            
            ret.push_back(levelSum / (double) levelCount);
            levelSum = 0;
        }
        
        return ret;
    }
};