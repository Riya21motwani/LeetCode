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
    
    void inorder(int &cnt,TreeNode* root, int k,int &find){
        if(cnt>=k || !root){
            return;
        }
       
        inorder(cnt,root->left,k,find);
        cnt++;
        if(k==cnt){
           find=root->val;
        }
        inorder(cnt,root->right,k,find);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        int find=0;
        inorder(cnt,root,k,find);
        return find;
    }
};