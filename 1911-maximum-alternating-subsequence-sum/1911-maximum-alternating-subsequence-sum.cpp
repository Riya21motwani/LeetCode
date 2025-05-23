class Solution {
public:

    long long f(int ind, int flag, vector<int>& nums ,  vector<vector<long long>>&dp){
        int n=nums.size();
        long long t1=INT_MIN;
        long long t2=INT_MIN;
        if(ind==n){
           return 0;
        }

        if(dp[ind][flag]!=-1){
            return dp[ind][flag];
        }
        if(flag==0){
            t1=max(nums[ind]+f(ind+1,1,nums,dp), f(ind+1,0,nums,dp));
        }
       
        else if(flag==1){
             t2=max(-nums[ind]+f(ind+1,0,nums,dp), f(ind+1,1,nums,dp));
        }

        return dp[ind][flag]=max(t1,t2);

    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return f(0,0, nums,dp);
    }
};