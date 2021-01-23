int dfs(Node* root) {
        if(!root) return 0;
        // Write your code here.
        return max(dfs(root->left), dfs(root->right)) + 1;
    }

    int height(Node* root) {
        return dfs(root) - 1;
    }