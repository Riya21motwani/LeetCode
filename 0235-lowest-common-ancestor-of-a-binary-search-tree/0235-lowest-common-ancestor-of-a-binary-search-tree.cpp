/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

TreeNode* f( TreeNode* root, TreeNode* p, TreeNode* q){
   
   if(root==NULL || root==p || root==q){
    return root;
   }
   TreeNode* leftside=f(root->left,p,q);
   TreeNode*rightside=f(root->right,p,q);
   if(leftside!=NULL && rightside!=NULL){
    return root;
   }else if(leftside!=NULL){
    return leftside;
   }else{
    return rightside;
   }
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};