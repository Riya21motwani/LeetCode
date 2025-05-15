class Solution {
public:


    int f(int i ,int j , vector<vector<int>>& dungeon ,  vector<vector<int>>&dp){
        int n=dungeon.size();
        int m=dungeon[0].size();
        if(j>=m || i>=n ){
            return 1e9;
        }
      

        if(i==n-1&& j==m-1){
            if(dungeon[i][j]<=0){
                return 1+abs(dungeon[i][j]);
            }
            return 1;
        }
         if(dp[i][j]!=-1){
            return dp[i][j];
        }
       int right=f(i+1,j,dungeon,dp);
       int down=f(i,j+1,dungeon,dp);
       
       int val=min(right,down)-dungeon[i][j];
       if(val<=0){
        return dp[i][j]=1;
       }
       return dp[i][j]=val;
    }
    

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(201,vector<int>(201,-1));
        return f(0,0,dungeon,dp);
        
    }
};