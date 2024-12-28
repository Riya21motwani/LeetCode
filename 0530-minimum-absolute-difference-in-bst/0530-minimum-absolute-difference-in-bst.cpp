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
    int mini=INT_MAX;
    void  f( TreeNode* root, TreeNode* &prev){

        if(root==NULL){
            return;
        }

         
       f(root->left,prev);

       if(prev!=NULL){
        mini=min(mini,abs(root->val-prev->val));
       }
       
       prev=root;
      
       f(root->right,prev);

    }

    int getMinimumDifference(TreeNode* root) {
        
        TreeNode*prev=NULL;
         f(root,prev);
        return mini;
    }
};