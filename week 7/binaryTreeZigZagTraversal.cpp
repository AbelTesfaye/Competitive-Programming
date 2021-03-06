class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector< vector<int> > ret;
        
        list< TreeNode * > ltr;
        list< TreeNode * > rtl;
        ltr.push_back(root);
        
        while(true){
            vector<int> currentRow;
            while(!ltr.empty()){
                if(ltr.front()->left) rtl.push_back(ltr.front()->left);
                if(ltr.front()->right) rtl.push_back(ltr.front()->right);
                    
                currentRow.push_back(ltr.front()->val);
                ltr.pop_front();
            }
            if(currentRow.size() != 0)
                ret.push_back(currentRow);
            currentRow = {};
            
            while(!rtl.empty()){
                if(rtl.back()->right) ltr.push_front(rtl.back()->right);
                if(rtl.back()->left) ltr.push_front(rtl.back()->left);
                
                currentRow.push_back(rtl.back()->val);
                rtl.pop_back();
            }
            if(currentRow.size() != 0)
                ret.push_back(currentRow);
            if(ltr.empty() && rtl.empty()) break;
            
        }
        return ret;
    }
};