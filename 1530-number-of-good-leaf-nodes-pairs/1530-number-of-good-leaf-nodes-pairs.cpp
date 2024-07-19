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
    
    void graph( TreeNode* root ,  TreeNode* prev , unordered_map<TreeNode*,vector<TreeNode*>>&adj , unordered_set<TreeNode*>&st ){
        
        if(root==NULL){

        return ;
        }
        if(root->left ==NULL && root->right==NULL){
            st.insert(root);
        }
        if(prev!=NULL){
            
            adj[prev].push_back(root);
            adj[root].push_back(prev);
        }
        
        graph(root->left,root,adj,st);
        graph(root->right,root,adj,st);
    }
    
    int countPairs(TreeNode* root, int distance) {
       unordered_map<TreeNode*,vector<TreeNode*>>adj;
        unordered_set<TreeNode*>st;
        graph(root,NULL, adj,st);
        int cnt=0;
        
       for(auto & it:st){
           queue<TreeNode*>q;
           q.push(it);
           unordered_set<TreeNode*>visit;
           visit.insert(it);
           for(int level=0;level<=distance;level++){
               int size=q.size();
               while(size--){
                    TreeNode*curr=q.front();
                   q.pop();
                   if(curr!=it && st.count(curr)){
                       cnt++;
                   }
                   for(auto neigh:adj[curr]){
                       if(!visit.count(neigh)){
                       q.push(neigh);
                       visit.insert(neigh);
                   }
                  }
               }
           }
       }
        return cnt/2;
        
    }
};