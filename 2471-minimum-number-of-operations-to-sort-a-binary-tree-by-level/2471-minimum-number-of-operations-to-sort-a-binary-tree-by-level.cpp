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

    int f(vector<int>&v , int &mini){
       int cntswap=0;
       int n=v.size();
       unordered_map<int,int>umap;
       for(int i=0;i<v.size();i++){
            umap[v[i]]=i;
       }
       vector<int>temp(v.begin(),v.end());
       sort(temp.begin(),temp.end());

       for(int i=0;i<n;i++){
       if(temp[i]!=v[i]){
            int ind=umap[temp[i]];
            swap(v[i],v[ind]);
            umap[v[i]]=i;
            umap[v[ind]]=ind;
            cntswap++;
       }
       }
       return cntswap;

    }



    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){

            int size=q.size();
            vector<int>v;
            int mini=INT_MAX;
            for(int i=0;i<size;i++){
              TreeNode*node=q.front();
               q.pop();
               mini=min(mini,node->val);
               v.push_back(node->val);
               if(node->left!=NULL){
                q.push(node->left);
               }
               if(node->right!=NULL){
                q.push(node->right);
               }
            
            }
            ans+=(f(v,mini));

        }

        return ans;
    }
};