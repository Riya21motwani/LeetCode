class Solution {
public:

    int f(int i, int j , int cnt,  vector<vector<int>>& coins, vector<vector<vector<int>>>&dp){
       int n=coins.size();
       int m=coins[0].size();

        if(i==n-1 && j==m-1){
            if(coins[i][j]<0){
               if(cnt>0){
                return 0;
               }else{
                return coins[i][j];
               }
            }else{
                return coins[i][j];
            }
        }

        

        if(i>=n || j>=m){
            return -1e9;
        }

        if(dp[i][j][cnt]!=-1e9){
            return dp[i][j][cnt];
        }
        int left=-1e9;
        int down=-1e9;


        if(coins[i][j]<0){
            //1st case
            if(cnt>0){
            left=f(i,j+1,cnt-1,coins,dp);
            down=f(i+1,j,cnt-1,coins,dp);
        } 
        
        }

        left=max(left,coins[i][j]+f(i,j+1,cnt,coins,dp));
        down=max(down,coins[i][j]+f(i+1,j,cnt,coins,dp));

        return dp[i][j][cnt]=max(left,down);
    }

    int maximumAmount(vector<vector<int>>& coins) {

       int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));
        return f(0, 0, 2, coins, dp);
    }
};