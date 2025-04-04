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

    TreeNode* f( TreeNode*root, unordered_map<int,int>&umap, int &maxi){

        if(root==NULL || umap[root->val]==maxi){
            return root;
        }

    
        TreeNode* t1 =f(root->left,umap,maxi);
        TreeNode* t2=f(root->right,umap,maxi);

        if(t1!=NULL && t2!=NULL){
            return root;
        }
        if(t1!=NULL){
            return t1;
        }
        
            return t2;

        
        

    }

    void finddepth(int d, TreeNode*root, unordered_map<int,int>&umap, int &maxi){
        if(root==NULL){
            return;
        }
        umap[root->val]=d;
        maxi=max(maxi,d);
        finddepth(d+1,root->left,umap,maxi);
        finddepth(d+1,root->right,umap,maxi);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<int,int>umap;
        int maxi=0;
        finddepth(0,root,umap,maxi);

        return f(root,umap,maxi);

    }
};