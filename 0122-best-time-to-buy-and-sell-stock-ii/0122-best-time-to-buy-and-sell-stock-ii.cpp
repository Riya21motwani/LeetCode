class Solution {
public:

    int f(int ind, int buy, vector<int>& prices , vector<vector<int>>&dp){
        int n=prices.size();
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        if(buy==0){
            return dp[ind][buy]=max(-prices[ind]+f(ind+1,1,prices,dp) , f(ind+1,0,prices,dp));
        }else{
            return dp[ind][buy]=max(+prices[ind]+f(ind+1,0,prices,dp) , f(ind+1,1,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,0,prices,dp);
    }
};