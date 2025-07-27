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
map<pair<int,int>,vector<TreeNode*>>umap;
    vector<TreeNode*> f(int i , int j){
        if(i>j){
            return {NULL};
        }
        if(i==j){
            return {new TreeNode(i)};
        }
        if(umap.find({i,j})!=umap.end()){
            return umap[{i,j}];
        }
        vector<TreeNode*>v;
        for(int k=i;k<=j;k++){
            vector<TreeNode*>left=f(i,k-1);
            vector<TreeNode*>right=f(k+1,j);
            for(auto l:left){
                for(auto r:right){
                    TreeNode*root=new TreeNode(k);
                    root->left=l;
                    root->right=r;
                    v.push_back(root);
                                 
                }
            }
        }
         return umap[{i,j}]=v;
    }

    vector<TreeNode*> generateTrees(int n) {
      
       return f(1,n);
    }
};