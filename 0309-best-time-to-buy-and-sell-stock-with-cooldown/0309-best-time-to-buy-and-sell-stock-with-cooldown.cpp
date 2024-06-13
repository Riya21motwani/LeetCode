class Solution {
public:
   int f(int ind,int buy, vector<int>& prices, vector<vector<int>>&dp){
        int n=prices.size();
        
        if( ind>=n){
            return 0;
        }
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy==1){
            profit=max(-prices[ind]+f(ind+1,0,prices,dp),f(ind+1,1,prices,dp));
        }else{
            profit=max(prices[ind]+f(ind+2,1,prices,dp),f(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        int profit=0;
        for(int buy=0;buy<=1;buy++){
            dp[n][buy]=0;
            dp[n+1][buy]=0;
        }
        
        for(int ind=n-1;ind>=0;ind--){
           
                    dp[ind][1]=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                
                   dp[ind][0]=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
                 
               
            
        }
        
        return dp[0][1];
        // return f(0,1,prices,dp);
    }
};