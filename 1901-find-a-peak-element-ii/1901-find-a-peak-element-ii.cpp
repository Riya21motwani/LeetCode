class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = m - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

          
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            bool leftOk = (mid == 0) || (mat[maxRow][mid] > mat[maxRow][mid-1]);
            bool rightOk = (mid == m-1) || (mat[maxRow][mid] > mat[maxRow][mid+1]);

            if (leftOk && rightOk) {
                return {maxRow, mid}; 
            } else if (mid > 0 && mat[maxRow][mid-1] > mat[maxRow][mid]) {
                r = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }
        return {-1, -1}; 
    }
};
