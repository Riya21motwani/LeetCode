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

    pair<int,int>f( TreeNode* root ,  int &ans){

        if(root==NULL){
            return {0,0};
        }

        pair<int,int>l1=f(root->left,ans);
        pair<int,int>l2=f(root->right,ans);
        
        int sum=(l1.first+l2.first+root->val);
        int cnt=(l1.second +l2.second+1);
        int avg=(sum)/cnt;
        if(avg==root->val){
            ans++;
        }
        return {sum , cnt };


    }


    int averageOfSubtree(TreeNode* root) {
        int ans=0;
       
        f(root,ans);
        return ans;
    }
};