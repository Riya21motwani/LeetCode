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

    int convert (string & binaryNumber){
    int decimalNumber = 0;
    for (size_t i = 0; i < binaryNumber.length(); i++) {
        decimalNumber = decimalNumber * 2 + (binaryNumber[i] - '0');
        }
        return decimalNumber;
    }

    
    int f(TreeNode* root, string ans){
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->val+'0');
            return convert(ans);
        }

        ans.push_back(root->val+'0');
        return f(root->left,ans)+f(root->right,ans);
        
    }

    int sumRootToLeaf(TreeNode* root) {

        string ans="";
        return f(root , ans);
    }
};