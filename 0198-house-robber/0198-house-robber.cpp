class Solution {
public:

    int f(int i, vector<int>& nums,vector<int>&dp){

        int n=nums.size();
        if(i<0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+f(i-2,nums,dp);
        int notake=f(i-1,nums,dp);
        return dp[i]=max(take,notake);

    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,INT_MIN);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int take=0;
            int notake=0;
            if(i-2>=0){
             take=nums[i]+dp[i-2];
            }
            if(i-1>=0){
             notake=dp[i-1];
            }
             dp[i]=max(take,notake);
        }
        return dp[n-1];
    }
};