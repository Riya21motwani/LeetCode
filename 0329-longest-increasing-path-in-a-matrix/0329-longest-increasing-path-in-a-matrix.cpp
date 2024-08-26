class Solution {
public:
    
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,-1,0,1};
  
    int dfs(int row, int col,vector<vector<int>>&dp , vector<vector<int>>& matrix ){
        int m=matrix.size();
        int n=matrix[0].size();
        
        if(dp[row][col]!=0){
            return dp[row][col];
        }
        int maxi=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 &&ncol>=0 &&nrow<m && ncol<n && matrix[nrow][ncol] > matrix[row][col] ){
               maxi=max(maxi , 1+dfs(nrow,ncol,dp,matrix));
                
            }
        }
        
        return dp[row][col]=maxi;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
         int maxill=1;
        vector<vector<int>>dp(m,vector<int>(n, 0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxill=max(maxill,dfs(i,j,dp,matrix));
            }
        }
      
        
        return maxill;
    }
};