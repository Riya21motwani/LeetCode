class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if (i == 0 && j == 0) return grid[i][j];
        if (i < 0 || j < 0) return 10000000;
        if (dp[i][j] != -1) return dp[i][j];
        int up = grid[i][j] + f(i-1, j, grid, dp);
        int left = grid[i][j] + f(i, j-1, grid, dp);
        return dp[i][j] = min(up, left);
    }
    // int minPathSum(vector<vector<int>>& grid) {
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // return f(m-1, n-1, grid, dp);

        int minPathSum (vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int>prev(n,0);
        vector<int>curr(n,0);
        // return f(m-1, n-1, grid, dp);
        
        for(int i=0;i<m;i++){
              for(int j=0;j<n;j++){
                   if (i == 0 && j == 0) curr[j]= grid[i][j];
                 else{int up = grid[i][j] ;

                   if(i-1>=0){
                    up+=prev[j] ;
                   }else{
                      up=INT_MAX;
                   }

                   int left=grid[i][j];
                   if(j-1>=0){
                    left+=curr[j-1] ;
                  
                   }else{
                        left=INT_MAX;
                   }
                     curr[j] = min(up, left);
              }
        }
        prev=curr;
        }
        
        return prev[n-1];
    
    }
};