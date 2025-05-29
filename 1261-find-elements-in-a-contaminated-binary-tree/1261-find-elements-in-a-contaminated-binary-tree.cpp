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
class FindElements {
public:
     unordered_map<int,int>umap;
    void f(TreeNode*root , int value){
        if(root==NULL){
            return;
        }
        root->val=value;

        umap[value]++;
        f(root->left,2*root->val+1);
        f(root->right,2*root->val +2);
    }

    FindElements(TreeNode* root) {
        
        f(root,0);
    }
    
    bool find(int target) {
        if(umap.find(target)!=umap.end()){
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */