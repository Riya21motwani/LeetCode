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

    int f(TreeNode* root){

         if(root==NULL ){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
       

        int l=f(root->left);
        int r=f(root->right);
        if(abs(r-l)>=2){
            return -1;
        }
         

         return 1+max(l,r);
    }
  

    bool isBalanced(TreeNode* root) {
        if(f(root)==-1){
            return false;
        }

        return true;
       
    }
};