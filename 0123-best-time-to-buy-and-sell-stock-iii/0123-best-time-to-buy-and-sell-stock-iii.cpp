class Solution {
public:
    
    int f(int ind, int buy,int limit,vector<int>& prices,vector<vector<vector<int>>>&dp){
      int n=prices.size();
        int profit=0;
        if(ind==n || limit==0)return 0;
        if(dp[ind][buy][limit]!=-1)return dp[ind][buy][limit];
        if(buy==1){
            return  dp[ind][buy][limit]=max(-prices[ind]+f(ind+1,0,limit,prices,dp) ,                          f(ind+1,1,limit,prices,dp));
        }
        
            return dp[ind][buy][limit]=max(prices[ind]+f(ind+1,1,limit-1,prices,dp),f(ind+1,0,limit,prices,dp));
        
    }
    
    
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
          vector<vector<int>>curr(2,vector<int>(3,0));
        vector<vector<int>>prev(2,vector<int>(3,0));
          // return f(0,1,2 ,prices,dp);
        
        for(int buy=0;buy<=1;buy++){
            for(int limit=0;limit<=2;limit++){
                prev[buy][limit]=0;
            }
        }
        
        for(int ind=0;ind<=n;ind++){
            for(int buy=0;buy<=1;buy++){
                prev[buy][0]=0;
            }
        }
        
        
          
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                      if(buy==1){
                       curr[buy][limit]=max(-prices[ind]+prev[0][limit], prev[1][limit]);
                     }
                  else{
                   curr[buy][limit]=max(prices[ind]+prev[1][limit-1],prev[0][limit]);
                }
             }
            }
            prev=curr; 
        }
        return prev[1][2];
    }
};