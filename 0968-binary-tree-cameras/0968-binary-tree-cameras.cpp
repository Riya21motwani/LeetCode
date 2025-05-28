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
int count = 0;
    
    void dfs(TreeNode* root, TreeNode* parent, unordered_set<TreeNode*>&uset) {
        if(!root)
            return;
        
        dfs(root->left, root,uset);
        dfs(root->right, root,uset);
        
       
        if((parent == NULL && uset.find(root) == uset.end()) || //Tree's root
           (root->left!=NULL && uset.find(root->left) == uset.end()) ||             
           (root->right!=NULL &&  uset.find(root->right) == uset.end())               
           ) {
            count++;
            
            uset.insert(parent); 
            uset.insert(root);
            uset.insert(root->left); 
            uset.insert(root->right); 
            
        }
    }
    int minCameraCover(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        
        
        count = 0;
        TreeNode* parent = NULL; 
        unordered_set<TreeNode*>uset;
        dfs(root, parent,uset);
        
        return count;
    }
};