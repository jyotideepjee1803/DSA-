#include<bits/stdc++.h>
vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                
                level.push_back(curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            ans.push_back(level);
        }
        
        return ans;
}
