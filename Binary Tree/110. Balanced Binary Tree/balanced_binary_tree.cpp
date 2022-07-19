#include<bits/stdc++.h>
using namespace std;

int dfsHeight(TreeNode *root){
        
        if(root == NULL) return 0;
        
        int lh = dfsHeight(root->left);
        int rh = dfsHeight(root->right);
        
        //if either of left/right subtree is unbalanced return -1
        if(lh == -1 || rh == -1) return -1;
        
        //unbalanced : 
        if(abs(lh-rh) > 1) return -1;
        
        //if not returned -1 then it's balanced BT
        return 1 + max(lh, rh);
}
    
bool isBalanced(TreeNode* root) {
        //if(root == NULL) return true;
        
        if(dfsHeight(root) != -1) return true;
        return false;
}
