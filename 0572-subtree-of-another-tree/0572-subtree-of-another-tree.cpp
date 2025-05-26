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

    bool check(TreeNode* r1, TreeNode* r2){

        if(r1==NULL && r2==NULL){
            return true;
        }
        if(r1==NULL || r2==NULL || r1->val!=r2->val){
            return false;
        }

        if(check(r1->left,r2->left)==false){
            return false;
        }
        if(check(r1->right,r2->right)==false){
            return false;
        }
        return true;

    }

    bool f(TreeNode* r1, TreeNode* r2){
        
        if(r1==NULL){
            return false;
        }


        if(r1->val==r2->val){
            if(check(r1,r2)==true){
                return true;
            }
        }

        return f(r1->left,r2) || f(r1->right,r2);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return f(root,subRoot);
    }
};