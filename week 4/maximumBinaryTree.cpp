class Solution {
public:
    TreeNode *dfs(vector<int> &nums, int l, int r){
        if(r < l) return NULL;
        
        int index = max_element(nums.begin() + l, nums.begin() + r + 1)  - nums.begin();
                
        return new TreeNode{
            nums[index],
            dfs(nums, l, index - 1), 
            dfs(nums, index + 1, r)};        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0 , nums.size() - 1);
    }
};