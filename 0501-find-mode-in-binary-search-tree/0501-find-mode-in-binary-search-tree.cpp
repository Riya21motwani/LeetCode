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
    
    void solve( TreeNode* root, unordered_map<int,int>&umap,vector<int>&ans ){
        if(root==NULL){
            return ;
        }
        
        solve(root->left ,umap,ans);
        umap[root->val]++;
        solve(root->right,umap,ans);
        
        
    }
    
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>umap;
        
        vector<int>ans;
        solve(root,umap,ans);
        int maxfreq=0;
        for(auto it:umap){
           int freq=it.second;
           maxfreq=max(maxfreq,freq);
            
           
            
        }
        
        
        for(auto it:umap){
            if(it.second==maxfreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};