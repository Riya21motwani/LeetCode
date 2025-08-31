class Solution {
public:

    int f(int n, vector<int>&dp){
        if(n==1 || n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
       int take=f(n-1,dp);
       int notake=f(n-2,dp);
        return dp[n]=take+notake;
    }
    int climbStairs(int n) {
        vector<int>dp(46,-1);
        return f(n,dp);
    }
};