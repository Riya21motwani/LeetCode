class Solution {
public:
    
    int f(int ind, int buy,int limit,vector<int>& prices,vector<vector<vector<int>>>&dp){
      int n=prices.size();
        int profit=0;
        if(ind==n || limit==0)return 0;
        if(dp[ind][buy][limit]!=-1)return dp[ind][buy][limit];
        if(buy==1){
            return  dp[ind][buy][limit]=max(-prices[ind]+f(ind+1,0,limit,prices,dp) , f(ind+1,1,limit,prices,dp));
        }
        
            return dp[ind][buy][limit]=max(prices[ind]+f(ind+1,1,limit-1,prices,dp),f(ind+1,0,limit,prices,dp));
        
    
          
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2 ,prices,dp);
    }
};