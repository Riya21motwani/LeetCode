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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size();
        unordered_map<int,TreeNode*>umap;
        unordered_set<int>uset;
        for(int i=0;i<n;i++){
            int p=descriptions[i][0];
            int c=descriptions[i][1];
            int l=descriptions[i][2];
            if(umap.find(p)==umap.end()){
                umap[p]=new TreeNode(p);
            }
            if(umap.find(c)==umap.end()){
                umap[c]=new TreeNode(c);
            }

            if(l==1){
                umap[p]->left=umap[c];
            }
            else{
                  umap[p]->right=umap[c];
            }
            
            uset.insert(c);
        }


        for(auto &it:descriptions){
            int parent=it[0];
            if(uset.find(parent)==uset.end()){
                return umap[parent];
            }
        }

        return new TreeNode(-1);
    }
};