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
    int maxLevel = 0;
    int dfs(TreeNode *node, int level){
        if(node == nullptr) return 0;
        
        int l = dfs(node->left, level + 1);
        int r = dfs(node->right, level + 1);
        
        node->val = max({l, r, level});
        maxLevel = max(maxLevel, node->val);
        
        return node->val;
    }
    
    TreeNode* LCA(TreeNode *node){
        TreeNode *ret = node;
        
        queue<TreeNode*> q;
        q.push(node);
        
        while(q.size() == 1){
            TreeNode* p = q.front(); q.pop();
            ret = p;
            
            if(p->left != nullptr && p->left->val == maxLevel){
                q.push(p->left);
            }
            
            if(p->right != nullptr && p->right->val == maxLevel){
                q.push(p->right);
            }
            
            if(q.size() == 2){
                break;
            }
        }
        
        return ret;
    }
    
    unordered_map<TreeNode*, int> m;
    
    void s(TreeNode *node){
        if(node == NULL) return;
        m[node] = node->val;
        s(node->left);
        s(node->right);
    }
    
    void r(TreeNode *node){
        if(node == NULL) return;
        node->val = m[node];
        r(node->left);
        r(node->right);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {        
        s(root);
        dfs(root, 0);
        
        auto ret = LCA(root);
        r(ret);
        
        return ret;
        
    }
};