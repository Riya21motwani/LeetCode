class Solution {
public:
    
    int solve(int ind,  int target ,vector<int>& nums, int n ,vector<vector<int>>&dp ){
        if(target==0){
            return 1;
        }
        if(ind>=n || target<0){
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int take=solve(0,target-nums[ind],nums,n,dp);
        int notake=solve(ind+1,target,nums,n ,dp);
        
        return dp[ind][target]=take+notake;
        
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(201,vector<int>(1001,-1));
        return solve(0,target,nums,n ,dp);
    }
};