#include<bit/stdc++.h>
int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        
        return 1 + max(left_height,right_height);
}
