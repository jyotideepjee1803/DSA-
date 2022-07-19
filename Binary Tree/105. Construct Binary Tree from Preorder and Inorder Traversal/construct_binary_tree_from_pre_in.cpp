#include<bits/stdc++.h>
using namespace std;

TreeNode* f(int s_pre, int s_in, int e_in,vector<int>& preorder, vector<int>& inorder, unordered_map<int,int> &mp){
        
        if(s_in > e_in || s_pre > preorder.size()-1){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[s_pre]);
        
        int idx = mp[root->val];
        
        if(s_in == e_in) return root;
        
        root->left = f(s_pre + 1, s_in, idx-1, preorder, inorder, mp);
        root->right = f(s_pre + idx - s_in + 1, idx+1, e_in, preorder, inorder, mp);
        
        return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        return f(0,0,inorder.size()-1,preorder,inorder,mp);
}
