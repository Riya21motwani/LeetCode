class Solution {
    

public:
    
    int f(int curr, int prevc, int n ,  vector<vector<int>>&dp){
     
        if(curr==n){
            return 0;
        }
        if(curr>n){
            return 100000000;
        }
        if(dp[curr][prevc]!=-1){
            return dp[curr][prevc];
        }
        int cap=2+f(curr+curr,curr,n , dp);
        int p=1+f(curr+prevc,prevc,n , dp);
        return dp[curr][prevc]=min(cap,p);
    }
    
    
    
    int minSteps(int n) {
         
        if(n==1){
            return 0;
        }
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        return 1+f(1,1,n , dp);
    }
    
};