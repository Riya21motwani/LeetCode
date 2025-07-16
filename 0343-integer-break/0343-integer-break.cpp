class Solution {
public:

    int f(int n , vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int maxi=INT_MIN;
        for(int i=1;i<n;i++){
            int curr=i*max((n-i),f(n-i,dp));
            maxi=max(maxi,curr);
        }
        return dp[n]=maxi;
    }

    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};