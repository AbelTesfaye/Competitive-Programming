/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int dfs(Node *node){
        if(node == NULL) return 0;
        
        int maxChild = 0;
        
        for(auto &c: node->children){
            maxChild = max(maxChild, dfs(c));
        }
        
        return 1 + maxChild;
    }
    int maxDepth(Node* root) {
        return dfs(root);
    }
};