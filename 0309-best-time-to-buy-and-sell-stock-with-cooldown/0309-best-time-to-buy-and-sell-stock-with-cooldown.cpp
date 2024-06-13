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
        vector<int>curr(2,0);
        vector<int>front1(2,0);
        vector<int>front2(2,0);
        int profit=0;
        for(int buy=0;buy<=1;buy++){
            front1[buy]=0;
            front2[buy]=0;
        }
        
        for(int ind=n-1;ind>=0;ind--){
           
                    curr[1]=max(-prices[ind]+front1[0],front1[1]);
                
                   curr[0]=max(prices[ind]+front2[1],front1[0]);
                 
               
            
            front2=front1;
             front1=curr;
        }
        
        return curr[1];
        // return f(0,1,prices,dp);
    }
};