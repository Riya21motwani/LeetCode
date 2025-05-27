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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode*newnode=new TreeNode(val);
            newnode->left=root;
            return newnode;
        }
        queue<TreeNode*>q;
        int cnt=1;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            cnt++;
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                if(cnt==depth){
                    TreeNode*n1=new TreeNode(val);
                    TreeNode*n2=new TreeNode(val);
                    n1->left=node->left;
                    n2->right=node->right;
                    node->left=n1;
                    node->right=n2;

                    


                }
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }

            }
           
        }
        return root;
    }
};