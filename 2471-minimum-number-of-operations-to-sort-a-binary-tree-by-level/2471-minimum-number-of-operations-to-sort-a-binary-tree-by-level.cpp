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

    int find(vector<int>&level, int mini){
        for(int i=0;i<level.size();i++){
            level[i]=level[i]-mini;
        }
        int i=0;
        int cnt=0;
        while(i<level.size()){
            while(level[i]!=i){
                swap(level[i],level[level[i]]);
                cnt++;
            }
            i++;
        }
        return cnt;

    }


    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        int op=0;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            int mini=INT_MAX;
            for(int i=0;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                mini=min(node->val,mini);
                level.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
                
            }
        
            op+=find(level,mini);
        }

        return op;
      
    }
};