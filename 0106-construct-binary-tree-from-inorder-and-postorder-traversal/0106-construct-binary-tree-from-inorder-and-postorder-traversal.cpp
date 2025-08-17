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

    TreeNode*f(int instart, int inend, int poststart, int postend, vector<int>& inorder, vector<int>& postorder, unordered_map<int,int>&umap){
        if(instart>inend || poststart>postend){
            return NULL;
        }
        TreeNode*root=new TreeNode(postorder[postend]);
        int inroot=umap[root->val];
        int numleft=inroot-instart;
 
        root->left=f(instart,inroot-1,poststart,poststart+numleft-1,inorder,postorder,umap);
        root->right=f(inroot+1,inend,poststart+numleft,postend-1,inorder,postorder,umap);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       unordered_map<int,int>umap;
       for(int i=0;i<inorder.size();i++){
        umap[inorder[i]]=i;
       }
        int n=inorder.size();
        int m=postorder.size();
       return f(0,n-1,0,m-1,inorder,postorder,umap);
    }
};