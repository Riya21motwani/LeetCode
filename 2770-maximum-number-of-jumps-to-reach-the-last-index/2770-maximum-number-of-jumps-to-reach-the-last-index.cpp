class Solution {
public:

    int f(int i, vector<int>& nums, int target, vector<int>&dp){
        int ans=-1e9;
        int n=nums.size();
        
        if(i==n-1){

            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        for(int j=i+1;j<n;j++){
            if(abs(nums[j]-nums[i])<=target){

                ans=max(ans, 1+f(j,nums,target,dp));
            }
        }

        return dp[i]=ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        
        vector<int>dp(n+1,INT_MIN);
        // if(f(0,nums,target,dp) <0){
        //     return -1;
        // }
        // return f(0,nums,target,dp);



        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            
        

            for(int j=i+1;j<n;j++){
               if(abs(nums[j]-nums[i])<=target && dp[j]!=INT_MIN){
                
                dp[i]=max(dp[i], 1+dp[j]);
            }
        }

        }
        if(dp[0]<0){
            return -1;
        }
        return dp[0];
    }
};