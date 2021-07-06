class Solution {
public:
    unordered_map<int, int> m;
    
    void dfs(TreeNode *node, int level){
        if(node == NULL) return;
        
        if(m.find(level) == m.end()) m[level] = INT_MIN;
        
        m[level] = max(m[level], node->val);
        
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
    
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        
        vector<int> ret;
        for(int i = 0; ;i++){
            if(m.find(i) == m.end()){
                break;
            }
            
            ret.push_back(m[i]);
        }
        
        return ret;
    }
};