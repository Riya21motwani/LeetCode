class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int maxi = 0;

        while(!q.empty()) {
            int size = q.size();
            long long mini = q.front().second;
            long long first, second;

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                long long val = q.front().second - mini;
                q.pop();

                if(i == 0) first = val;
                if(i == size - 1) second = val;

                if(node->left)
                    q.push({node->left, 2 * val + 1});

                if(node->right)
                    q.push({node->right, 2 * val + 2});
            }

            maxi = max(maxi, (int)(second - first + 1));
        }

        return maxi;
    }
};