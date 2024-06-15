class Solution {
public:
    
    int f(int ind,int x, vector<int>& rewardValues , vector<vector<int>>&dp){
        int n=rewardValues.size();
        if(ind==n)return 0;
        if(dp[ind][x]!=-1)return dp[ind][x];
        
        int take=0;
        if(rewardValues[ind]>x){
            take=rewardValues[ind]+f(ind+1,x+rewardValues[ind],rewardValues,dp)  ;
        }
        int notake=f(ind+1,x,rewardValues,dp);
        return dp[ind][x]= max(take,notake);
    }
    
    int maxTotalReward(vector<int>& rewardValues) {
        int n=rewardValues.size();
        sort(rewardValues.begin(),rewardValues.end());
        vector<vector<int>>dp(2001,vector<int>(4001,-1));
        return f(0,0,rewardValues,dp);
    }
};