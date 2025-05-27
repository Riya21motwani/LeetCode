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

    int f( TreeNode* root, int maxi){
        if(root==NULL){
            return 0;
        }
        int t1=0;
        if(root->val>=maxi){
            t1=1;
            maxi=root->val;
        }

        return t1+ f(root->left,maxi)+f(root->right,maxi);


    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return f(root,root->val);
    }
};