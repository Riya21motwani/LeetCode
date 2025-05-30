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

    TreeNode* lca( TreeNode* root, int &maxdepth , unordered_map<int,int>&umap){
        if(root==NULL){
            return NULL;
        }
        if(umap[root->val]==maxdepth){
            return root;
        }
        TreeNode* lh=lca(root->left,maxdepth,umap);
        TreeNode* rh=lca(root->right,maxdepth,umap);
        if(lh!=NULL && rh!=NULL){
            return root;
        }else{
            if(lh!=NULL){
                return lh;
            }else{
                return rh;
            }
        }
    }

    void dfs( TreeNode* root ,  unordered_map<int,int>&umap , int d, int &maxdepth){

        if(root==NULL){
            return;
        }
        umap[root->val]=d;
        maxdepth=max(maxdepth,d);
        dfs(root->left,umap,d+1,maxdepth);
        dfs(root->right,umap,d+1,maxdepth);
    }
    

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
       unordered_map<int,int>umap;
       int maxdepth=0;
       int d=0;
       dfs(root,umap,d, maxdepth);
       return lca(root,maxdepth,umap);
    }
};