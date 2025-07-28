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

   

    unordered_map<TreeNode*,int>umap;

    int  f(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(umap.find(root)!=umap.end()){
            return umap[root];
        }
       int take=root->val
       + (root->left == NULL ? 0 : f(root->left->left)) 
       +(root->left==NULL ? 0 : f(root->left->right))
       +(root->right==NULL ? 0: f(root->right->left))
       +(root->right==NULL ? 0:f(root->right->right));

       int notake=f(root->left)+f(root->right);

       return umap[root]=max(take,notake);

    }

    int rob(TreeNode* root) {
       return f(root);

        
    }
};