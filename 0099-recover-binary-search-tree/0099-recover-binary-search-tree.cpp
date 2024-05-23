/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode*prev;
        TreeNode*first;
        TreeNode*last;
        TreeNode*middle;
    void find( TreeNode*root){
          if(!root)return;
        find(root->left);
        
           if( prev!=NULL  && root->val<prev->val){
                 if(!first){
                  first=prev;
                     middle=root;
                 }
               last=root;
           
        }
        prev=root;
        find(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        prev,first,middle,last=nullptr;
        find(root);
       if(first && last) {
           swap(first->val,last->val);
       } else if(first && middle) {
           swap(first->val,last->val);
       }
        
        return;
        
    }
};