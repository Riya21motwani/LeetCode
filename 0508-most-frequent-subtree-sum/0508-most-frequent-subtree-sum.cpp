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
    int maxi=0;
    int f(TreeNode*root,unordered_map<int,int>&umap , int sum){

        if(root==NULL){
            return 0;
        }
         int left=f(root->left,umap,sum);
         int right=f(root->right,umap,sum);

        umap[root->val+left+right]++;
        maxi=max(maxi,umap[root->val+left+right]);
        

        return root->val +left+right;

        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>umap;
        int sum=0;
        f(root,umap,sum);
        
        vector<int>ans;
        
        for(auto it:umap){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};