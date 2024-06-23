class Solution {
public:
    
    long long  f(int ind,int flag , vector<int>& nums ,vector<vector<long long>>&dp){
        int n=nums.size();
        if(ind==n)return 0;
        if(dp[ind][flag]!=-1)return dp[ind][flag];
        long long take=0;
        
        if(flag==1){
              take=nums[ind]+f(ind+1,0,nums,dp);
        }else{
            take= -nums[ind]+f(ind+1,1,nums,dp);
        }
        
       long long alltake=nums[ind]+f(ind+1,0,nums,dp);
        
        return dp[ind][flag]=max(take,alltake);
    }
    
    
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return f(0,1,nums,dp);
    }
};



