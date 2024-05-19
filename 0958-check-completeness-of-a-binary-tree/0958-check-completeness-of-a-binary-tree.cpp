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
    
    bool solve(TreeNode* root){
         
        queue<TreeNode*>q;
        q.push(root);
        bool findnull=false;
        while(!q.empty()){
         TreeNode*node=q.front();
            q.pop();
            if(node==NULL){
               findnull=true;
            }
            else{
                 if(findnull==true){
                      return false;
                 }
                q.push(node->left);
                  q.push(node->right);
            }
            
            
            
        }
        return true;
    }
    
    bool isCompleteTree(TreeNode* root) {
        
        return solve(root);
        
        
    }
};