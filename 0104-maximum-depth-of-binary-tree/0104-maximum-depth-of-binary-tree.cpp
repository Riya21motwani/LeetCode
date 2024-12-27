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

    int f( TreeNode* root){
        if(root==NULL ){
            return INT_MIN;
        }

        if(root->left==NULL  && root->right==NULL){
            return 1;
        }
        
        int left=f(root->left);
        int right=f(root->right);

        return 1+max(left,right);
    }

    int maxDepth(TreeNode* root) {
        return f(root);
    }
};