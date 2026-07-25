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
    int maxi=INT_MIN;
    int f(TreeNode* root){
        if(root==NULL)return 0;

        int lh=f(root->left);
        int rh=f(root->right);
        maxi=max(maxi, lh+rh+ root->val);
        return max(0,root->val +max(lh, rh));
    }
    int maxPathSum(TreeNode* root) {
        
        f(root);
        return maxi;
    }
};