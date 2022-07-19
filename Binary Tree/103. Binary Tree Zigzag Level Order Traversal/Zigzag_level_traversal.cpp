#include<bit/stdc++.h>
using namespace std;
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool LtoR = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                
                int idx = LtoR ? i : size-1-i;
                
                level[idx] = curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            LtoR = !LtoR;
            ans.push_back(level);
        }
        
        return ans;
}
