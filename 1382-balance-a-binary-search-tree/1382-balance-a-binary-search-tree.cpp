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
    
    void inordert(TreeNode* root, vector<int>& inorder) {
       
        if(root==NULL)return;
        
        inordert(root->left,inorder);
        inorder.push_back(root->val);
        inordert(root->right,inorder);
    }

    TreeNode* createBST(const vector<int>& inorder, int s,
            
                        int e) {
        
        if(s>e)return NULL;
        int mid=s+(e-s)/2;
        
        TreeNode* root=new TreeNode(inorder[mid]);
        root->left=createBST(inorder,s,mid-1);
        root->right=createBST(inorder,mid+1,e);
 
       return root;
    }
    
     TreeNode* balanceBST(TreeNode* root) {
         vector<int>inorder;
         inordert(root,inorder);
         return createBST(inorder,0,inorder.size()-1);
    }
};