class Solution {
public:
    
    int f(int ind,int buy, vector<int>& prices, vector<vector<int>>&dp,int fee){
        int n=prices.size();
        
        if(ind==n){
            return 0;
        }
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy==1){
            profit=max(-prices[ind]+f(ind+1,0,prices,dp,fee),f(ind+1,1,prices,dp,fee));
        }else{
            profit=max(prices[ind]+f(ind+1,1,prices,dp,fee)-fee,f(ind+1,0,prices,dp,fee));
        }
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        
                
          int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,-1));
        
        vector<int>prev(2,0);
        vector<int>curr(2,0);
        
        
        for(int ind=n-1;ind>=0;ind--){
           
                 int profit=0;
                
                  curr[1]=max(-prices[ind]+prev[0],prev[1]);
                
                    curr[0]=max(prices[ind]+prev[1]-fee,prev[0]);
                  
                  prev=curr;
            
        }
        
        
        
        return curr[1];
        
        
        
        
        // return f(0,1,prices,dp,fee);

        
        
    }
};