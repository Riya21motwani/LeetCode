class Solution {
public:
    
//     int f(int ind,int buy, vector<int>& prices, vector<vector<int>>&dp){
//         int n=prices.size();
        
//         if(ind==n){
//             return 0;
//         }
//         if(dp[ind][buy]!=-1)return dp[ind][buy];
//         int profit=0;
//         if(buy==1){
//             profit=max(-prices[ind]+f(ind+1,0,prices,dp),f(ind+1,1,prices,dp));
//         }else{
//             profit=max(prices[ind]+f(ind+1,1,prices,dp),f(ind+1,0,prices,dp));
//         }
//         return dp[ind][buy]=profit;
//     }
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>prev(2,0),curr(2,0);
        
        // return f(0,1,prices,dp);
         int profit=0;
      for(int ind=n-1;ind>=0;ind--){
          for(int buy=0;buy<=1;buy++){
              
        if(buy==1){
            profit=max(-prices[ind]+prev[0],prev[1]);
        }else{
            profit=max(prices[ind]+prev[1],prev[0]);
        }
        curr[buy]=profit;
          }
          prev=curr;
      }
      return prev[1];
    }
};