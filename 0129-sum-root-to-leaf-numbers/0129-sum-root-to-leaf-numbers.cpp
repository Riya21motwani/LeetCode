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

    void f( TreeNode* root , int &sum , string temp){
        if(root==NULL){
            return;
        }
        temp+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            sum+=stoi(temp);
            return;
        }
        f(root->left,sum,temp);
        f(root->right,sum,temp);

    }


    int sumNumbers(TreeNode* root) {
        int sum=0;
        string temp="";
        f(root,sum,temp);
        return sum;
    }
};