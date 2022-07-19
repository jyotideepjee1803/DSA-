#include<bits/stdc++.h>
using namespace std;

TreeNode* sortedListToBST(ListNode* head) {
        
        //Corner case : 
        if(head == NULL){
            return NULL;
        }
        
        //only one node :
        if(head->next == NULL){
            
            return new TreeNode(head->val);
        }
        
        //for only 2 node :
        if(head->next->next == NULL){
            TreeNode* root=new TreeNode(head->val);
            root->right=new TreeNode(head->next->val);
            return root;
        }
        
        
        //MAIN :
        ListNode *fast = head, *slow = head, *pre;
        //get mid : 
        while(fast and fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //diconnect before middle to form a half list : 
        pre->next = NULL;
        
        TreeNode *root = new TreeNode(slow->val);
        
        //recursive for both halves :
        
        //left subtree contains head->beforeMid :
        root->left = sortedListToBST(head);
        //right subtree contains afterMid->tail : 
        root->right = sortedListToBST(slow->next);
        
        return root;
}
