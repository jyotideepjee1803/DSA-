#include<bits/stdc++.h>
using namespace std;
TreeNode *f(vector<int>& postorder, vector<int>& inorder,int& postIndex,int s,int e){
        
        if(s>e || postIndex<0 ){
              ++postIndex;
              return NULL;
         }
        
        TreeNode *root = new TreeNode(postorder[postIndex]);
        
        int idx = 0;
        for(int i=0;i<inorder.size();i++){
            if(root->val == inorder[i]) idx = i;
        }
        
        root->right = f(postorder, inorder, --postIndex, idx+1, e);
        root->left =  f(postorder, inorder, --postIndex, s, idx-1);
        
        return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int postIndex = postorder.size()-1;
        
        return f(postorder,inorder,postIndex,0,inorder.size()-1);
}
