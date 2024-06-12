class Solution {
public:
    
     int f(int ind, int tran,vector<int>& prices,vector<vector<int>>&dp){
      int n=prices.size();
//         int profit=0;
//         if(ind==n || limit==0)return 0;
//         if(dp[ind][buy][limit]!=-1)return dp[ind][buy][limit];
//         if(buy==1){
//             return  dp[ind][buy][limit]=max(-prices[ind]+f(ind+1,0,limit,prices,dp) ,                          f(ind+1,1,limit,prices,dp));
//         }
        
//             return dp[ind][buy][limit]=max(prices[ind]+f(ind+1,1,limit-1,prices,dp),f(ind+1,0,limit,prices,dp));
         
         
         if(ind==n || tran==4){
             return 0;
         }
         if(dp[ind][tran]!=-1)return dp[ind][tran];
         if(tran%2==0){
             return dp[ind][tran]=max(-prices[ind] +f(ind+1,tran+1,prices,dp), f(ind+1,tran,prices,dp));
         }
             return dp[ind][tran]=max(prices[ind]+f(ind+1,tran+1,prices,dp),f(ind+1,tran,prices,dp));
        
         
         
        
    }
    
    
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
       
        vector<vector<int>>dp(n,vector<int>(4,-1));
        
          return f(0,0,prices,dp);
        
          
        
    }
};