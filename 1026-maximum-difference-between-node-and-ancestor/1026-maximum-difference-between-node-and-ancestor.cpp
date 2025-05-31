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

    void f( TreeNode* root , int currmin, int currmax , int &maxi){

        if(root==NULL){
            return;
        }
        maxi=max({maxi,abs(root->val-currmin) , abs(root->val-currmax)});
        currmin=min(currmin,root->val);
        currmax=max(currmax,root->val);
        f(root->left,currmin,currmax,maxi);
        f(root->right,currmin,currmax,maxi);


    }

    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxi=0;
        f(root,root->val,root->val,maxi);
        return maxi;
    }
};