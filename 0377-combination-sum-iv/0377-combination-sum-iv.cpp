class Solution {
public:

    int f( int t, vector<int>& nums , vector<int>&dp){
        if(t==0){
            return 1;
        }
        if(t<0){
            return 0;
        }
        if(dp[t]!=-1){
            return dp[t];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
           ans+= f(t-nums[i],nums,dp);
        }
        return dp[t]=ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return f(target,nums,dp);
      
    }
};