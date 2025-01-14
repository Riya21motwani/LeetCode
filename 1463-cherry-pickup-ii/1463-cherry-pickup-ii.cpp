class Solution {
public:
    
//     int f(int i,int j1,int j2,int n,int m, vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
//          if(j1<0 || j1>=m ||j2<0 || j2>=m){
//              return -1e9;
//          }
//         if(i==n-1){
//               if(j1==j2){
//                     return grid[i][j1];
//               }else{
//                     return grid[i][j1]+grid[i][j2];
//               }
//         }
//         if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
//         int maxi=INT_MIN;
        
//         for(int dj1=-1;dj1<=1;dj1++){
//             for(int dj2=-1;dj2<=1;dj2++){
//                 int ans=0;
//                 if(j1==j2)ans+=grid[i][j1];
//                 else ans+=grid[i][j1]+grid[i][j2];
//                 ans+=f(i+1,j1+dj1,j2+dj2,n,m,grid,dp);
//                 maxi=max(maxi,ans);
//             }
//         }
//         return dp[i][j1][j2]= maxi;  
//     }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
       
//        return f(0,0,m-1,n,m,grid,dp);
        
        
        
        
        //base case;
        
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2)dp[n-1][j1][j2]=grid[n-1][j1];
                else{
                      dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
                }
            }
        }
      
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                 for(int j2=0;j2<m;j2++){
                       int maxi=INT_MIN;
                       for(int dj1=-1;dj1<=1;dj1++){
                            for(int dj2=-1;dj2<=1;dj2++){
                              int ans=0;
                               if(j1==j2)ans+=grid[i][j1];
                                else ans+=grid[i][j1]+grid[i][j2];
                                if( j1+dj1<0 || j1+dj1>=m || j2+dj2<0 || j2+dj2>=m ){
                                  
                                     ans += -1e9;
                                }else{
                                     ans+=dp[i+1][j1+dj1][j2+dj2];
                                }
                                 maxi=max(maxi,ans);
                               
                                }
                         }
                     dp[i][j1][j2]=maxi;
                 }
            }
        }
        
        
        return dp[0][0][m-1];
        
    }
};