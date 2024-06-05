class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
     int n =coins.size();
 
    vector<vector<int>> dp(n, vector<int>(amount+ 1, 0));

    for(int i=0;i<=amount;i++){
        if(i%coins[0]==0)dp[0][i]=i/coins[0];
        else{
            dp[0][i]=1e9;
        }
    }
    for(int ind=1;ind<n;ind++){
        for(int j=0;j<=amount;j++){
             int nottake=dp[ind-1][j];
             int pick=INT_MAX;
               if(coins[ind]<=j){
              pick=1+dp[ind][j-coins[ind]];
          }
     dp[ind][j]= min(pick,nottake);
        }
    }
   int ans=dp[n-1][amount];
   if(ans>=1e9){
       return -1;
   }
   return ans;
    }
};