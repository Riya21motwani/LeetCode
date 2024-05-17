/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     void mark_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent_track , TreeNode* target){
        queue<TreeNode*>q;
         q.push(root);
         while(!q.empty()){
           TreeNode*node=q.front();
           q.pop();
             if(node->left){
               parent_track[node->left]=node;
                 q.push(node->left);
             }
             if(node->right){
               parent_track[node->right]=node;
                 q.push(node->right);
             }
         }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        mark_parent(root,parent_track,target);
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>vis;
        vis[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size=q.size();
            if(curr_level==k)break;
            curr_level++;
            
          for(int i=0;i<size;i++){
            TreeNode*curr=q.front();
            q.pop();
        if(curr->left && !vis[curr->left]){
              q.push(curr->left);
            vis[curr->left]=true;
        }
            if(curr->right && !vis[curr->right]){
              q.push(curr->right);
            vis[curr->right]=true;
        }
            if(parent_track[curr] && !vis[parent_track[curr]]){
              q.push(parent_track[curr]);
            vis[parent_track[curr]]=true;
        }
            
        }
        }   
        vector<int>res;
        while(!q.empty()){
            TreeNode*current=q.front();
            q.pop();
            res.push_back(current->val);
            
        }
        return res;
    }
};