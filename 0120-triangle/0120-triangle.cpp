class Solution {
public:
    
    int f(int i,int j, vector<vector<int>>& triangle, vector<vector<int>>&dp){
        int n=triangle.size();
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int d=triangle[i][j]+f(i+1,j,triangle,dp);
        int dia=triangle[i][j]+f(i+1,j+1,triangle,dp);
        return dp[i][j]=min(d,dia);
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,triangle,dp);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                 if(i==n-1){
                     dp[i][j]= triangle[i][j];
                  }
                   int d=triangle[i][j]+f(i+1,j,triangle,dp);
                 int dia=triangle[i][j]+f(i+1,j+1,triangle,dp);
                dp[i][j]=min(d,dia);
            }
        }
        return dp[n-1][n-1];
    }
};